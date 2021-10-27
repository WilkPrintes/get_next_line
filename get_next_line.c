/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wilkp90@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:56:53 by wprintes          #+#    #+#             */
/*   Updated: 2021/10/26 12:49:47 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_line(char *buffer, int buffer_size, int fd);
int n_exists(char *buffer);
size_t find_n (char *buffer);

char *get_next_line(int fd)
{
    char *buffer;
    char *result;
    static char *backup;

    if(fd < 0 || BUFFER_SIZE <= 0 )
        return (NULL);
    buffer = ft_strdup("");
    buffer = read_line(buffer, BUFFER_SIZE, fd);
    if (backup)
    {
        buffer = ft_strjoin(backup, buffer);
    }
    while (n_exists(buffer) != 1)
    {
        buffer = ft_strjoin(buffer, read_line(buffer, BUFFER_SIZE, fd));
    }
    result = malloc (sizeof(char) * find_n (buffer));
    ft_memmove(result, buffer, find_n (buffer));
    backup = buffer + find_n (buffer) + 1;
    if (ft_strlen(backup) != 0)
        result[find_n(buffer)] = '\n';
    return (result);
}

int n_exists(char *buffer)
{
    size_t counter;

    counter = ft_strlen(buffer);
    if (counter <= 0)
        return (1);
    while (counter > 0)
    {
        if (*buffer == '\n' || *buffer == '\0' || *buffer < 0)
            break ;
        buffer++;
        counter--;
    }
    if (counter > 0)
        return (1);
    return (0);

}

size_t find_n (char *buffer)
{
    size_t counter;

    counter = 0;

    while(buffer[counter] != '\0' && buffer[counter] != '\n')
        counter++;
    return (counter);
}

char *read_line(char *buffer, int buffer_size, int fd)
{
    buffer = malloc(sizeof(char) * buffer_size);
    if (buffer == NULL)
        return (NULL);
    read(fd, buffer, buffer_size);
    return (buffer);
}
