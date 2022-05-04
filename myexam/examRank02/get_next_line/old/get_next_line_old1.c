#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int		i;
	
	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		get_newline(char *s)
{
	int		i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *s)
{
	char	*res;
	int		len;
	int		i;

	len = ft_strlen(s);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if(!(res = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	i = 0;
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		res[len1 + i] = s2[i];
		i++;
	}
	free(s1);
	res[len1 + len2] = '\0';
	return (res);
}

int					split_line(char **backup, char **line, int newline)
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

int					return_all(char **backup, char **line, int read_size, int newline)
{

	if (read_size < 0)
		return (-1);
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

int		get_next_line(char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char *backup;
	int			read_size;
	int			newline;

	if (!line)
		return (-1);
	backup = ft_strdup("");
	while ((read_size = read(0, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		backup = ft_strjoin(backup, buf);
		if ((newline = get_newline(backup)) >= 0)
			break;
	}
	return (return_all(&backup, line, read_size, newline));
}
