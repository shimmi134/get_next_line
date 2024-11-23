/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:34:40 by shimi-be          #+#    #+#             */
/*   Updated: 2024/11/23 15:55:23 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strchr(char *str, int flag)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	printf("Str: %s\n",str);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (flag)
			{
				if (str[i+1] == '\0')
					return (NULL);
				return (ft_strjoin(NULL,&str[i+1]));
			}
			else
			{
				if (str[i+1]== '\0')
					return (NULL);
				return (&str[i+1]);
			}
		}
		i++;
	}
	return (NULL);
}


char *trim_line(char *str)
{
	char	*arr;
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	arr = (char *)malloc(sizeof(char) * (len +1));
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = str[i];
		i++;
	}
	arr[len] = '\0';
	return (arr);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *arr;
	int i;
	int j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	arr = (char *)malloc(sizeof(char)*(i+j)+1);
	if (!arr)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			arr[i] = s1[i];
			i++;	
		}
	}
	if (s2)
	{
		j = 0;
		while (s2[j])
		{
			arr[i+j]=s2[j];
			j++;
		}
	}
	arr[i+j] = '\0';
	return (arr);
}

char	*get_line(char *stash, int fd)
{
	int	bytes_read;
	char	*buff;
	char	*arr;
	char	*temp;

	stash = NULL;
	arr = NULL;
	temp = NULL;
	buff = (char *)malloc(BUFFER_SIZE+1);
	if (!buff)
		return (NULL);
	bytes_read = 1;
	buff[0]='\0';
	while (bytes_read > 0 && !temp)
	{
		free (temp);
		temp = ft_strchr(buff,1);
		bytes_read = read(fd,buff,BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buff[bytes_read] = '\0';
			arr = ft_strjoin(stash,buff);
			free(stash);
			stash = arr;
		}
		else if (bytes_read < 0)
			return (NULL);
	}
	free(buff);
	free(temp);
	return (arr);
}
