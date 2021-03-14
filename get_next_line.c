/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jejeong <jejeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:02:58 by jejeong           #+#    #+#             */
/*   Updated: 2021/02/05 22:25:15 by jejeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_latest_str(char *latest_str)
{
	char	*saved_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!latest_str)
		return (0);
	while (latest_str[i] && latest_str[i] != '\n')
		i++;
	if (!latest_str[i])
	{
		free(latest_str);
		return (0);
	}
	if (!(saved_str = malloc(sizeof(char) * ((ft_strlen(latest_str) - i) + 1))))
		return (0);
	i++;
	while (latest_str[i])
		saved_str[j++] = latest_str[i++];
	saved_str[j] = '\0';
	free(latest_str);
	return (saved_str);
}

char	*ft_one_line(char *str)
{
	int		i;
	char	*one_line;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(one_line = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		one_line[i] = str[i];
		i++;
	}
	one_line[i] = '\0';
	return (one_line);
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*latest_str;
	int				size;

	size = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (LINE_ERR);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (LINE_ERR);
	while (!ft_newline_check(latest_str) && size != 0)
	{
		if ((size = read(fd, buf, BUFFER_SIZE)) < 0)
		{
			free(buf);
			return (LINE_ERR);
		}
		buf[size] = '\0';
		latest_str = ft_strjoin(latest_str, buf);
	}
	free(buf);
	*line = ft_one_line(latest_str);
	latest_str = ft_latest_str(latest_str);
	if (size == 0)
		return (LINE_END);
	return (LINE_READ);
}
