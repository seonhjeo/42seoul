/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:50:26 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/01/05 14:42:55 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_path(char *str)
{
	struct stat s;
	char *temp;
	char *path;
	int i;

	i = -1;
	temp = ft_strjoin("/", str);
	while (g_data.env_path[++i])
	{
		path = ft_strjoin(g_data.env_path[i], temp);
		if (!stat(path, &s))
			return (path);
		free(path);
	}
	free(temp);
	return (0);
}

char	*delete_quote(char *str)
{
	char	*temp;
	char	c;
	int		i;
	int		j;

	i = -1;
	j = 0;
	c = 0;
	temp = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (str[++i])
	{
		if (is_quot(str[i]) && !c)
			c = str[i];
		if (str[i] != c)
			temp[j++] = str[i];
	}
	temp[j] = '\0';
	free(str);
	return (temp);
}

void free_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char *ft_strjoin_token(char *s1, char *s2)
{
	char *res;
	size_t len1;
	size_t len2;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, s1, len1 + 1);
	free(s1);
	ft_strlcat(res + len1, s2, len2 + 1);
	return (res);
}
