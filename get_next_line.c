/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wilkp90@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:56:53 by wprintes          #+#    #+#             */
/*   Updated: 2021/11/14 22:53:05 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *buffer, int fd, ssize_t size, char **backup);
int		n_exists(char *buffer);
char *free_null(char *str1);

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		size;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof (char) *(BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	size = read (fd, buffer, BUFFER_SIZE);
	if (size <= 0)
	{
		if (!backup)
			return (free_null(buffer));
		free (buffer);
		size = ft_strlen(backup);
		buffer = ft_strdup(backup);
		backup = free_null(backup);
	}
	buffer[size] = '\0';
	return (read_line(buffer, fd, size, &backup));
}

char *free_null(char *str1)
{
	free(str1);
	return (NULL);
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

char	*read_line(char *buffer, int fd, ssize_t size, char **backup)
{
	char	*temp;
	char	*temp2;
	char	*result;

	temp = ft_strdup(buffer);
	if (*backup != NULL)
	{
		temp2 = ft_strdup(temp);
		free(temp);
		temp = ft_strjoin(*backup, temp2);
		free(temp2);
		*backup = free_null(*backup);
	}
	while (n_exists(buffer) != 1 && size > 0)
	{
		free(buffer);
		buffer = malloc(sizeof (char) *(BUFFER_SIZE + 1));
		size = read (fd, buffer, BUFFER_SIZE);
		buffer[size] = '\0';
		temp2 = ft_strjoin(temp, buffer);
		free(temp);
		temp = ft_strdup(temp2);
		free(temp2);
	}
	free(buffer);
	result = ft_substr(temp, 0, find_n(temp) + 1);
	if (ft_strlen(result) < ft_strlen(temp))
		*backup = ft_substr(temp, find_n(temp) + n_exists(result), ft_strlen(temp));
	free(temp);
	if(ft_strlen(result) == 0)
		return (free_null(result));
	return (result);
}
