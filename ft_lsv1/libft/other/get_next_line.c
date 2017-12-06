/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 22:34:54 by flseaill          #+#    #+#             */
/*   Updated: 2017/11/16 17:43:37 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	add_line(char **tmpcontent, char *buff)
{
	char		*tmp;

	tmp = NULL;
	if (*tmpcontent)
	{
		tmp = ft_strdup(*tmpcontent);
		ft_memdel((void **)tmpcontent);
		*tmpcontent = ft_strjoin(tmp, buff);
		free(tmp);
		tmp = NULL;
	}
	else
		*tmpcontent = ft_strdup(buff);
}

static int	readline(char **tmpcontent, char **line)
{
	char		*tmp;

	tmp = ft_strchr(*tmpcontent, '\n');
	if (tmp)
	{
		*line = ft_strsub(*tmpcontent, 0, tmp - *tmpcontent);
		ft_memmove(*tmpcontent, tmp + 1, ft_strlen(tmp));
		tmp = NULL;
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*content = NULL;
	char		buff[BUFF_SIZE + 1];
	int			i;

	if (BUFF_SIZE == 0)
		return (0);
	if (fd < 0 || !line)
		return (-1);
	if (content && readline(&content, line))
		return (1);
	while ((i = read(fd, buff, BUFF_SIZE)))
	{
		if (i == -1)
			return (-1);
		buff[i] = '\0';
		add_line(&content, buff);
		if (readline(&content, line))
			return (1);
	}
	if (!content || content[0] == '\0')
		return (0);
	*line = content;
	content = NULL;
	return (1);
}
