/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:55:52 by shimi-be          #+#    #+#             */
/*   Updated: 2024/11/23 18:54:19 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char *av[])
{
    int fd;
	int i = 0;
    char *line;

    fd = open(av[1], O_RDONLY);
	ac = fd;
    while ((line = get_next_line(fd)) != NULL)
    {
		printf("Iter:  %i",i);
		i++;
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
