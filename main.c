/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wilkp90@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:27:15 by wprintes          #+#    #+#             */
/*   Updated: 2021/11/03 21:53:21 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void bom_dia(int *a);

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