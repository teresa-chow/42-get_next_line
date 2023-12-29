/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:12:24 by tchow-so          #+#    #+#             */
/*   Updated: 2023/12/29 13:15:17 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* calculate length of string */
int	ft_strlen_gnl(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/* find char in string */
char	*ft_strchr_gnl(const char *str, int c)
{
	while ((*str) && ((unsigned char)*str != (unsigned char)c))
		str++;
	if ((unsigned char)*str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
}

/* join two strings */
// review need of ptr_s1
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s3;
	char	*ptr_s1;
	int		len;
	int		i;

	ptr_s1 = s1;
	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	s3 = malloc(sizeof(char) * (len + 1));
	if (!s3)
		return (NULL);
	i = 0;
	while (*s1)
		s3[i++] = *s1++;
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = '\0';
	if (ptr_s1)
		free(ptr_s1);
	return (s3);
}
