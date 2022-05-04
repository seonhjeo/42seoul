/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:48:17 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/03/23 12:13:39 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_prec_buf_str(char *str, int prec, int len)
{
	int		i;
	char	*buf;

	if (prec > -1)
		prec = return_prec_or_len2(prec, len);
	else
		prec = len;
	buf = (char *)malloc(sizeof(char) * (prec + 1));
	if (!buf)
		return (0);
	i = 0;
	while (i < prec)
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int	ft_add_width_str(char **buf, t_info *info)
{
	char	*width;
	int		i;

	if (info->width <= (int)ft_strlen(*buf))
		return ((int)ft_strlen(*buf));
	width = (char *)malloc(sizeof(char) * (info->width - ft_strlen(*buf) + 1));
	i = 0;
	while ((size_t)i < info->width - ft_strlen(*buf))
	{
		width[i] = return_zero_or_space(info->zero);
		i++;
	}
	width[i] = '\0';
	if (info->minus == 0)
		*buf = ft_strjoin(width, *buf, 3);
	else
		*buf = ft_strjoin(*buf, width, 3);
	return (info->width);
}

int	ft_print_str(char *str, t_info *info)
{
	int		res;
	char	*buf;

	res = 0;
	if (str == NULL)
		str = "(null)";
	if ((info->prec == -1) || ((size_t)info->prec > ft_strlen(str)))
		info->prec = ft_strlen(str);
	buf = ft_prec_buf_str(str, info->prec, ft_strlen(str));
	res = ft_add_width_str(&buf, info);
	ft_putstr_fd(buf, _STDIN);
	free(buf);
	return (res);
}
