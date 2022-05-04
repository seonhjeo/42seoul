/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:14:56 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 12:42:01 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

#define BUFFER_SIZE 32

static int	is_newline(char *backup)
{
	int				i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	split_line(char **backup, char **line, int newline)
{
	char			*temp;
	int				len;

	(*backup)[newline] = '\0';
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + newline + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	temp = ft_strdup(*backup + newline + 1);
	free(*backup);
	*backup = temp;
	return (1);
}

static int	return_all(char **backup, char **line, int read_size)
{
	int				newline;

	if (read_size < 0)
		return (-1);
	newline = is_newline(*backup);
	if (*backup && newline >= 0)
		return (split_line(backup, line, newline));
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char		*backup[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				read_size;
	int				newline;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			break ;
		buf[read_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf, 1);
		newline = is_newline(backup[fd]);
		if (newline >= 0 || read_size <= 0)
			break ;
	}
	return (return_all(&backup[fd], line, read_size));
}
