/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:28:02 by marcrodr          #+#    #+#             */
/*   Updated: 2021/07/23 18:28:05 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	search_line_break(char **buf, size_t *scissor)
{
	int	i;

	i = 0;
	if (!*buf)
		return (0);
	while ((*buf)[i] != '\0')
	{
		if ((*buf)[i] == '\n')
		{
			*scissor = i;
			return (1);
		}
		i++;
	}
	return (0);
}

static char	*cut_line(char **buf, size_t *scissor)
{
	int		i;
	char	*tmp;
	char	*line;

	i = 0;
	line = NULL;
	if (!*buf)
		return (NULL);
	tmp = ft_strdup(*buf);
	if (search_line_break(&*buf, &*scissor))
	{
		line = ft_substr(*buf, 0, *scissor + 1);
		free(*buf);
		*buf = ft_substr(tmp, *scissor + 1, ft_strlen(tmp));
	}
	else
	{
		i = ft_strlen(tmp);
		if (i > 0)
			line = ft_substr(tmp, 0, i);
		free(*buf);
		*buf = NULL;
	}
	free(tmp);
	return (line);
}

static void	set_buf(char **buf, char **tmp, char **readed)
{
	if (!*buf)
		*buf = ft_strdup(*readed);
	else
	{
		*tmp = ft_strdup(*buf);
		free(*buf);
		*buf = ft_strjoin(*tmp, *readed);
		free(*tmp);
	}
}

char	*get_next_line(int fd)
{
	size_t        scissor;
	size_t        qtd_read;
	static char    *buf[256];
	char        *readed;
	char        *tmp;

	if (fd < 0 || read(fd, NULL, 0) != 0 || BUFFER_SIZE < 0)
		return (NULL);
	readed = malloc(BUFFER_SIZE + 1);
	qtd_read = read(fd, readed, BUFFER_SIZE);
	scissor = 0;
	while (qtd_read > 0)
	{
		(readed)[qtd_read] = '\0';
		set_buf(&buf[fd], &tmp, &readed);
		if (search_line_break(&buf[fd], &scissor))
			break ;
		qtd_read = read(fd, readed, BUFFER_SIZE);
	}
	free(readed);
	return (cut_line(&buf[fd], &scissor));
}
