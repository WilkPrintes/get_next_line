/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wilkp90@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:56:53 by wprintes          #+#    #+#             */
/*   Updated: 2021/11/03 23:39:48 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_line(char *buffer, int buffer_size, int fd);
int		n_exists(char *buffer);
size_t	find_n(char *buffer);

char	*get_next_line(int fd)
{
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	buffer = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (read (fd, buffer, BUFFER_SIZE) == 0)
		return (NULL);
	return(read_line(buffer, BUFFER_SIZE, fd));
}

int	n_exists(char *buffer)
{
	size_t	counter;

	counter = 0;
	if (!buffer)
		return (0);
	while (buffer[counter] != '\0' && buffer[counter] != '\n')
		counter++;
	if (counter < ft_strlen(buffer))
		return (1);
	return (0);
}

size_t	find_n(char *buffer)
{
	size_t	counter;

	counter = 0;
	while (buffer[counter] != 0 && buffer[counter] != '\n')
		counter++;
	return (counter);
}

char	*read_line(char *buffer, int buffer_size, int fd)
{
	ssize_t size;
	char *temp;
	char *result;
	static char *backup;

	temp = malloc(sizeof(char) * 9999);
	temp = ft_strdup(buffer);
	if (backup != NULL)
	{
		temp = ft_strdup(backup);
		backup = NULL;
	}
	buffer = malloc(sizeof(char) * buffer_size);
	while(n_exists(buffer) != 1 && size > 0)
	{
		size = read (fd, buffer, buffer_size);
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	result = malloc(sizeof(char) * find_n(temp) + 1);
	ft_memmove(result, temp, find_n(temp));
	if (size != 0)
	{
		backup = temp + find_n(temp) + 1;
		result[find_n(temp)] = '\n';
	}
	free(temp);
	return (result);
}