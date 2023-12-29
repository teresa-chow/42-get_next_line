/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:04:54 by tchow-so          #+#    #+#             */
/*   Updated: 2023/12/29 12:45:28 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h> // O_RDONLY
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("file.txt", O_RDONLY);
	str = get_next_line(fd);
	printf ("%s", str);
	free(str);
	str = get_next_line(fd);
	printf ("%s", str);
	free(str);
	str = get_next_line(fd);
	printf ("%s", str);
	free(str);
	str = get_next_line(fd);
	printf ("%s", str);
	free(str);
	str = get_next_line(fd);
	printf ("%s", str);
	free(str);
	str = get_next_line(fd);
	printf ("%s", str);
	free(str);
	return (close(fd));
}
