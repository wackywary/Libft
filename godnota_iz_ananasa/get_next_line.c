/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:24:35 by jpasty            #+#    #+#             */
/*   Updated: 2019/05/22 15:40:57 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int				ft_next_line(char **hold, int fd, char **line)
{
	char		*tmp;
	int		len;

	len = 0;
	while (hold[fd][len] != '\n' && hold[fd][len] != '\0')
		len++;
	if (hold[fd][len] == '\n')
	{
		*line = ft_strsub(hold[fd], 0, len);
		tmp = ft_strdup(hold[fd] + len + 1);
		free(hold[fd]);
		hold[fd] = tmp;
		if (hold[fd][0] == '\0')
			ft_strdel(&hold[fd]);
	}
	else if (hold[fd][len] == '\0')
	{
		*line = ft_strdup(hold[fd]);
		ft_strdel(&hold[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char *hold[FD_MAX + 1];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd > FD_MAX || !line || (read(fd, NULL, 0) < 0))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!hold[fd])
			hold[fd] = ft_strnew(0);
		tmp = ft_strjoin(hold[fd], buf);
		free(hold[fd]);
		hold[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret == 0 && hold[fd] == NULL)
		return (0);
	return (ft_next_line(hold, fd, line));
}
