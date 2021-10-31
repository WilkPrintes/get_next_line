/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wilkp90@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:27:15 by wprintes          #+#    #+#             */
/*   Updated: 2021/10/31 14:57:52 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("./test.txt", O_RDONLY);
	printf("%s|\n", get_next_line(fd));
	printf("%s|\n", get_next_line(fd));
	printf("%s|\n", get_next_line(fd));
	printf("%s|\n", get_next_line(fd));
	printf("%s|\n", get_next_line(fd));
	printf("%s|\n", get_next_line(fd));
	printf("%s|\n", get_next_line(fd));
	printf("%s|\n", get_next_line(fd));
	printf("%s|\n", get_next_line(fd));
	printf("%s|\n", get_next_line(fd));
	printf("%s|\n", get_next_line(fd));
	printf("%s|\n", get_next_line(fd));
	printf("%s|\n", get_next_line(fd));
	printf("%s|\n", get_next_line(fd));
}
