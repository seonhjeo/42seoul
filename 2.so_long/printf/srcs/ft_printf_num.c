/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:11:17 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/03/23 11:37:55 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_add_pointer_prefix(char **buf)
{
	*buf = ft_strjoin("0x", *buf, 2);
	return (ft_strlen(*buf));
}

int	add_minus(t_info *info, char **buf)
{
	int		len;

	len = 0;
	if ((info->type == 'i' || info->type == 'd')
		&& info->zero == 0 && info->nbr_sign == -1)
	{
		*buf = ft_strjoin("-", *buf, 2);
		len = 1;
	}
	return (len);
}

int	add_minus2(int len, t_info *info, char **buf)
{
	int		len_to_add;

	len_to_add = 0;
	if (info->nbr_sign == -1 && info->zero == 1)
	{
		if (len >= info->width)
		{
			*buf = ft_strjoin("-", *buf, 2);
			len_to_add = 1;
		}
		else if (len < info->width)
			*buf[0] = '-';
	}
	return (len_to_add);
}

int	ft_prec_buf_num(unsigned long long num, t_info *info, char **buf)
{
	int		len;
	int		res;
	int		i;

	len = ft_check_len_num(num, info);
	res = return_prec_or_len(len, info->prec);
	*buf = (char *)malloc(sizeof(char) * (res + 1));
	if (!(*buf))
		return (_ERROR);
	i = ft_put_prec_num(len, 0, res, buf);
	i = 1;
	if (num == 0 && info->prec != 0)
		(*buf)[res - i] = '0';
	while (num)
	{
		(*buf)[res - i] = ft_return_base(info->type)[num % info->nbr_base];
		num /= info->nbr_base;
		i++;
	}
	(*buf)[res] = '\0';
	return (res);
}

int	ft_print_num(unsigned long long num, t_info *info)
{
	char	*buf;
	int		len;
	int		res;

	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)num < 0)
	{
		info->nbr_sign = -1;
		num = -num;
	}
	len = ft_prec_buf_num(num, info, &buf);
	len += add_minus(info, &buf);
	if (info->type == 'p')
		len = ft_add_pointer_prefix(&buf);
	res = ft_add_width_str(&buf, info);
	res += add_minus2(len, info, &buf);
	ft_putstr(buf);
	free(buf);
	return (res);
}
