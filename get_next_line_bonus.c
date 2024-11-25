/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:34:32 by shimi-be          #+#    #+#             */
/*   Updated: 2024/11/25 19:20:30 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*find_nl(char *arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (NULL);
	while (arr[i])
	{
		if (arr[i] == '\n')
			return (arr);
		i++;
	}
	return (NULL);
}

char	*mall_buff(void)
{
	char	*buff;

	buff = (char *) malloc (BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff[0] = '\0';
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*arr;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	temp = NULL;
	if (!stash[fd] || !ft_strchr(stash[fd], 0))
	{
		if (stash[fd] && !ft_strchr(stash[fd], 0))
			temp = ft_strjoin(NULL, stash[fd]);
		free(stash[fd]);
		stash[fd] = get_line(stash[fd], fd, 1);
		arr = stash[fd];
		stash[fd] = ft_strjoin(temp, stash[fd]);
		free(arr);
		free(temp);
	}
	arr = trim_line(stash[fd]);
	if (!arr)
		return (free(stash[fd]), NULL);
	temp = stash[fd];
	stash[fd] = ft_strchr(stash[fd], 1);
	return (free(temp), arr);
}
