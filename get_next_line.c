/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wilkp90@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:56:53 by wprintes          #+#    #+#             */
/*   Updated: 2021/11/07 22:29:56 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_line(char *buffer, size_t buffer_size, int fd, ssize_t size, char **backup);
int		n_exists(char *buffer);
ssize_t	find_n(char *buffer);

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		size;
	static char	*backup;
	
	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	buffer = 0;
	buffer = malloc(sizeof(char) *(BUFFER_SIZE + 1));
	size = read (fd, buffer, BUFFER_SIZE);
	if (size == 0)	
	{
		if (backup)
		{
			free (buffer);
			buffer = malloc (sizeof (char) * ft_strlen(buffer));
			buffer = ft_strdup(backup);
			free(backup);
		}
		else
		{
			free (buffer);
			return (NULL);
		}
	}
	return(read_line(buffer, BUFFER_SIZE, fd, size, &backup));
}

int	n_exists(char *buffer)
{
	ssize_t	counter;

	counter = 0;
	if (!buffer)
		return (0);
	while (buffer[counter] != '\0' && buffer[counter] != '\n')
		counter++;
	if (counter < ft_strlen(buffer))
		return (1);
	return (0);
}

ssize_t	find_n(char *buffer)
{
	ssize_t	counter;

	counter = 0;
	while (buffer[counter] != 0 && buffer[counter] != '\n')
		counter++;
	return (counter);
}

char	*read_line(char *buffer, size_t buffer_size, int fd, ssize_t size, char **backup)
{
	ssize_t total;
	char *temp;
	char *result;
	char *temp2;

	total = 0;
	buffer[size] = '\0';
	temp = ft_strdup(buffer);
	if (*backup != NULL)
	{
		temp2 = ft_strdup(temp);
		temp = ft_strjoin(*backup, temp2);
		free(temp2);
		free(*backup);
		*backup = NULL;
	}
	while(n_exists(buffer) != 1 && size > 0)
	{
		size = read (fd, buffer, buffer_size);
		buffer[size] = '\0';
		temp2 = ft_strjoin(temp, buffer);
		free(temp);
		temp = ft_strdup(temp2);
		free(temp2);
		total = total + size;
	}
	free(buffer);
	result = malloc(sizeof(char) * (find_n(temp)));
	ft_memmove(result, temp, find_n(temp));
	if (size != 0)
	{
		result[find_n(temp)] = '\n';
		*backup = ft_strdup(temp + find_n(temp) + 1);
	}
	free(temp);
	return (result);
}