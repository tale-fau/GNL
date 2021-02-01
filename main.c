/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:46:07 by tale-fau          #+#    #+#             */
/*   Updated: 2021/02/01 14:52:53 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	int		fd1;
	int		fd2;
	int		ret;
	char	*line;

	fd1 = open(av[ac - 2], O_RDONLY);
	while ((ret = get_next_line(fd1, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	printf("%d\n\n", ret);
	ret = 0;
	fd2 = open(av[ac - 1], O_RDONLY);
	while ((ret = get_next_line(fd2, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	printf("%d\n", ret);
	return (0);
}
