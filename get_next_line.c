/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:23:49 by tchow-so          #+#    #+#             */
/*   Updated: 2023/12/29 13:28:23 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_from_fd(char *str, int fd);
char	*get_line(char *str);
char	*clear_line(char *str);

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	str = read_from_fd(str, fd);
	line = get_line(str);
	str = clear_line(str);
	return (line);
}

/* read BUFFER_SIZE bytes from file (identified by fd) */
char	*read_from_fd(char *str, int fd)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_gnl(str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoin_gnl(str, buffer);
	}
	free(buffer);
	return (str);
}

/* get line from 'str' and terminate it */
char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		line = malloc(i + 1);
	else
		line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/* clear previous line from 'str' */
char	*clear_line(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str[i] && (str[i] != '\n'))
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	tmp = malloc(sizeof(char) * (ft_strlen_gnl(str) - i + 1));
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	i++;
	j = 0;
	while (str[i])
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	free(str);
	return (tmp);
}
// GET NEXT LINE
/* 	1. checks vality of fd and BUFFER_SIZE values;
	2. reads BUFFER_SIZE bytes from file (identified by its descriptor, fd)
		2.1. allocates memory space to buffer
			(pre-defined macro BUFFER_SIZE + 1);
		2.2. checks for successful memory allocation;
		2.3. checks if newline character is found, and if there are
			still bytes to be read, otherwise frees memory;
		2.4. null-terminates buffer;
		2.5. joins buffer-sized strings to 'str' until newline
			character is found;
		2.6. frees 'buffer'';
		2.7. returns 'str' (start to end of line);
	3. gets line from str
		3.1. checks for empty str;
		3.2. increments index 'i' until newline character or
			null-terminator	is found;
		3.3. allocates memory according to scenario (+1 for '\0',
			+2 for '\n\0');
		3.4. copies str;
	4. clears previous line
		4.1. increments 'str' index until finding newline character;
		4.2. checks for 'str';
		4.3. allocates memory to temporary variable 'tmp';
		4.4. checks successful memory allocation;
		4.5. copies 'str' content after newline character is found
			to 'tmp';
		4.6. null-terminates 'tmp';
		4.7. frees 'str';
		4.8. returns 'tmp';
	5. returns line */
