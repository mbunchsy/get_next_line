/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:50:41 by mramos-j          #+#    #+#             */
/*   Updated: 2019/12/11 17:52:54 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strchr(const char *s, int c)
{
	char	*sc;

	sc = (char *)s;
	while (*sc && *sc != (char)c)
		sc++;
	return ((*sc == (char)c) ? sc : 0);
}

static void	ft_strdel(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

int			ft_putline(int fd, char **s, char **line)
{
	int		size;
	char	*tmp;

	size = 0;
	while (s[fd][size] != '\n')
		size++;
	*line = ft_substr(s[fd], 0, size);
	tmp = ft_strdup(&s[fd][size + 1]);
	free(s[fd]);
	s[fd] = tmp;
	return (1);
}

int			ft_output(int fd, char **line, int pline, char **s)
{
	if (pline < 0)
		return (-1);
	else if (pline == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
	{
		*line = ft_strdup("");
		ft_strdel(&s[fd]);
		return (0);
	}
	else if (ft_strchr(s[fd], '\n'))
		return (ft_putline(fd, s, line));
	else
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	int			pline;
	char		*buf;
	static char	*s[4096];
	char		*tmp;

	if (line == NULL || fd < 0 || BUFFER_SIZE < 1 || (read(fd, s[fd], 0) < 0))
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((pline = read(fd, buf, BUFFER_SIZE)))
	{
		buf[pline] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	free(buf);
	return (ft_output(fd, line, pline, s));
}
