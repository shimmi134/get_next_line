/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:44:51 by shimi-be          #+#    #+#             */
/*   Updated: 2024/11/25 19:19:39 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_line(char *stash, int fd, int br);
char	*trim_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int flag);
char	*get_next_line(int fd);
char	*find_nl(char *arr);
char	*mall_buff(void);
int		ft_strlen(char *str);

#endif
