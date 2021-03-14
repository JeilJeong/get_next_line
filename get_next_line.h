/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jejeong <jejeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:24:26 by jejeong           #+#    #+#             */
/*   Updated: 2021/02/05 16:24:36 by jejeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define LINE_READ 1
# define LINE_END 0
# define LINE_ERR -1

char	*ft_latest_str(char *latest_str);
char	*ft_one_line(char *str);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(char const *str);
void	*ft_memmove(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_newline_check(char *str);

#endif
