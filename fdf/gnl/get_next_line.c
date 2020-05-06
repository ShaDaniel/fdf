/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:59:23 by tjonella          #+#    #+#             */
/*   Updated: 2020/05/06 23:30:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		line_join(char **line, char *buf, t_list **ptr)
{
	char *tofree;

	tofree = NULL;
	tofree = (*line ? *line : NULL);
	if (ft_strchr(buf, 10))
	{
		*line = (*line ? ft_strnjoin(*line, buf, ft_strchr(buf, 10) - buf) :\
				ft_strndup(buf, ft_strchr(buf, 10) - buf));
		free(tofree);
		tofree = ((*ptr)->content ? (*ptr)->content : NULL);
		(*ptr)->content = ft_strdup(ft_strchr(buf, 10) + 1);
		if (!ft_strlen((*ptr)->content))
		{
			free((*ptr)->content);
			(*ptr)->content = NULL;
		}
		free(tofree);
		return (0);
	}
	else
	{
		*line = (*line ? ft_strjoin(*line, buf) : ft_strdup(buf));
		free(tofree);
		return (1);
	}
}

static int		preliminary(int fd, t_list **list, t_list **ptr, char **line)
{
	*line = NULL;
	if (!*list)
	{
		*list = ft_lstnew(NULL, fd);
		(*list)->content_size = fd;
	}
	*ptr = *list;
	while ((*ptr)->next && (*ptr)->content_size != (size_t)fd)
		*ptr = (*ptr)->next;
	if ((*ptr)->content_size != (size_t)fd)
		ft_lstadd(list, *ptr = ft_lstnew("", fd));
	if ((*ptr)->content)
	{
		if (line_join(line, (*ptr)->content, ptr) == 1)
		{
			free((*ptr)->content);
			(*ptr)->content = NULL;
			return (1);
		}
		else
			return (0);
	}
	return (2);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*ptr;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	int				prelim;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	prelim = preliminary(fd, &list, &ptr, line);
	while (prelim && (ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if (!line_join(line, buf, &ptr))
			break ;
	}
	if (ret == 0 && prelim == 2 && !*line)
	{
		*line = ft_strnew(0);
		return (0);
	}
	else
		return (1);
}
