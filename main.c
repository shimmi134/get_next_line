/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:55:52 by shimi-be          #+#    #+#             */
/*   Updated: 2024/11/22 22:19:21 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
	int i = 0;

    fd = open("hi.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
		printf("Iter %i",i);
		i++;
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
