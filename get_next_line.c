/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wilkp90@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:56:53 by wprintes          #+#    #+#             */
/*   Updated: 2021/11/12 18:04:08 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_line(char *buffer, int fd, ssize_t size, char **backup);
int		n_exists(char *buffer);
ssize_t	find_n(char *buffer);

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		size;
	static char	*backup;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = 0;
	if (backup && n_exists(backup) == 1)
	{
		buffer = malloc(sizeof (char) * (find_n(backup) + 1));
		ft_memmove(buffer, backup, find_n(backup) + 1);
		buffer[find_n(backup) + 1] = '\0';
		temp = ft_strdup(backup + find_n(backup) + 1);
		free(backup);
		backup = ft_strdup(temp);
		free(temp);
		return (buffer);
	}
	buffer = malloc(sizeof (char) *(BUFFER_SIZE + 1));
	size = read (fd, buffer, BUFFER_SIZE);
	if (size <= 0)
	{
		if (backup)
		{
			free (buffer);
			size = ft_strlen(backup);
			buffer = ft_strdup(backup);
			free(backup);
			backup = NULL;
		}
		else
		{
			free (buffer);
			return (NULL);
		}
	}
	return (read_line(buffer, fd, size, &backup));
}

int	n_exists(char *buffer)
{
	ssize_t	counter;

	counter = 0;
	if (ft_strlen(buffer) <= 0)
		return (0);
	while (buffer[counter] != '\0' && buffer[counter] != '\n')
		counter++;
	if (buffer[counter] == '\n')
		return (1);
	return (0);
}

ssize_t	find_n(char *buffer)
{
	ssize_t	counter;

	counter = 0;
	while (buffer[counter] != '\0' && buffer[counter] != '\n')
		counter++;
	return (counter);
}

char	*read_line(char *buffer, int fd, ssize_t size, char **backup)
{
	ssize_t	total;
	char	*temp;
	char	*result;
	char	*temp2;

	total = size;
	buffer[size] = '\0';
	temp = ft_strdup(buffer);
	if (*backup != NULL)
	{
		temp2 = ft_strdup(temp);
		free(temp);
		temp = ft_strjoin(*backup, temp2);
		free(temp2);
		free(*backup);
		*backup = NULL;
	}
	while (n_exists(buffer) != 1 && size > 0)
	{
		size = read (fd, buffer, BUFFER_SIZE);
		buffer[size] = '\0';
		temp2 = ft_strjoin(temp, buffer);
		free(temp);
		temp = ft_strdup(temp2);
		free(temp2);
		total = total + size;
	}
	free(buffer);
	result = malloc(sizeof(char) * (find_n(temp) + 1));
	ft_memmove(result, temp, find_n(temp) + 1);
	if ((total > ft_strlen(result) && size != 1) || ((total == BUFFER_SIZE)&& size != 1))
		*backup = ft_strdup(temp + find_n(temp) + 1);
	result[find_n(temp) + 1] = '\0';
	free(temp);
	return (result);
}
