/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:34:32 by shimi-be          #+#    #+#             */
/*   Updated: 2024/11/23 17:33:44 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*stash = NULL;
	char	*buff[1];
	char	*arr;
	char	*temp;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd,buff,BUFFER_SIZE) < 0)
		return (NULL);
	temp = NULL;
	if (!stash || !ft_strchr(stash,0))
	{
		if (stash && !ft_strchr(stash,0))
		{
			temp = ft_strjoin(NULL,stash);
			free(stash);
		}
		stash = get_line(stash,fd);
		arr = stash;
		stash = ft_strjoin(temp,stash);
		free(arr);
		free(temp);
		temp = NULL;
		arr = NULL;
	}
	arr = trim_line(stash);
	if (!arr)
		return (free(stash),NULL);
	temp = stash;
	stash = ft_strchr(stash,1);
	free(temp);
	//if (!stash) 
//		return (free(arr),NULL);
	return (arr);
}
