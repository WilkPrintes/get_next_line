/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wilkp90@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:56:53 by wprintes          #+#    #+#             */
/*   Updated: 2021/11/15 00:28:53 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(char *buffer, int fd, ssize_t size, char **backup);
static int	has_nl(char *buffer);
static char	*free_null(char *str);
static void	new_backup(char **backup, char **temp, char **aux);

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		size;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	size = read(fd, buffer, BUFFER_SIZE);
	if (size <= 0)
	{
		if (!backup)
			return (free_null(buffer));
		free(buffer);
		size = ft_strlen(backup);
		buffer = ft_strdup(backup);
		backup = free_null(backup);
	}
	buffer[size] = '\0';
	return (read_line(buffer, fd, size, &backup));
}

static char	*free_null(char *str)
{
	free(str);
	return (NULL);
}

static int	has_nl(char *buffer)
{
	size_t	counter;

	counter = 0;
	if (ft_strlen(buffer) <= 0)
		return (0);
	while (buffer[counter] != '\0' && buffer[counter] != '\n')
		counter++;
	if (buffer[counter] == '\n')
		return (1);
	return (0);
}

static char	*read_line(char *buffer, int fd, ssize_t size, char **backup)
{
	char	*temp;
	char	*aux;

	temp = ft_strdup(buffer);
	if (*backup != NULL)
		new_backup(backup, &temp, &aux);
	while (has_nl(buffer) != 1 && size > 0)
	{
		free(buffer);
		buffer = malloc(sizeof (char) * (BUFFER_SIZE + 1));
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = '\0';
		aux = ft_strjoin(temp, buffer);
		free(temp);
		temp = ft_strdup(aux);
		free(aux);
	}
	free(buffer);
	aux = ft_substr(temp, 0, find_n(temp) + 1);
	if (ft_strlen(aux) < ft_strlen(temp))
		*backup = ft_substr(temp, find_n(temp) + has_nl(aux), ft_strlen(temp));
	free(temp);
	if (ft_strlen(aux) == 0)
		return (free_null(aux));
	return (aux);
}

static void	new_backup(char **backup, char **temp, char **aux)
{
	*aux = ft_strdup(*temp);
	free(*temp);
	*temp = ft_strjoin(*backup, *aux);
	free(*aux);
	*backup = free_null(*backup);
}
