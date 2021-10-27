/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wilkp90@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:04:17 by wprintes          #+#    #+#             */
/*   Updated: 2021/10/26 12:28:34 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join(char *s1_val, char *s2_val, char *result);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*s1_val;
	char	*s2_val;

	if (!s1 || !s2)
		return (NULL);
	s1_val = (char *)s1;
	s2_val = (char *)s2;
	result = malloc(sizeof(char) * (ft_strlen(s1_val) + ft_strlen(s2_val)) + 1);
	if (result == NULL)
		return (NULL);
	result = join(s1_val, s2_val, result);
	return (result);
}

char	*join(char *s1_val, char *s2_val, char *result)
{
	size_t	counter;

	counter = 0;
	while (s1_val[counter] != '\0')
	{
		result[counter] = s1_val[counter];
		counter++;
	}
	counter = 0;
	while (s2_val[counter] != '\0')
	{
		result[ft_strlen(s1_val) + counter] = s2_val[counter];
		counter++;
	}
	result[ft_strlen(s1_val) + counter] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	count;
	char	*dest_value;
	char	*src_value;

	src_value = (char *) src;
	dest_value = (char *) dest;
	count = 0;
	if (dest > src)
	{
		while (count < n)
		{
			dest_value[n - count - 1] = src_value[n - count - 1];
			count++;
		}
	}
	else if (dest < src)
	{
		while (count < n)
		{
			dest_value[count] = src_value[count];
			count++;
		}
	}
	return (dest);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	len;
	char	*s;

	len = ft_strlen(str) + 1;
	s = (char *)malloc(sizeof(char) * len);
	if (s == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		s[i] = str[i];
	return (s);
}