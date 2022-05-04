/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:36:07 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/03/23 11:33:00 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_return_base(char type)
{
	if (type == 'u' || type == 'd' || type == 'i')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

int	ft_check_len_num(unsigned long long num, t_info *info)
{
	int		n;

	if (num == 0 && info->prec != 0)
		return (1);
	n = 0;
	while (num)
	{
		num /= info->nbr_base;
		n++;
	}
	return (n);
}

void	init_info(t_info *info)
{
	info->minus = 0;
	info->nbr_base = 10;
	info->nbr_sign = 0;
	info->prec = -1;
	info->type = 0;
	info->width = 0;
	info->zero = 0;
	info->final_len = 0;
}

int	ft_print_format(va_list ap, t_info *info)
{
	int		res;
	char	type;

	res = 0;
	type = info->type;
	if (type == 'c')
		res = ft_print_char(va_arg(ap, int), info);
	else if (type == '%')
		res = ft_print_char('%', info);
	else if (type == 's')
		res = ft_print_str(va_arg(ap, char *), info);
	else if (type == 'd' || type == 'i')
		res = ft_print_num(va_arg(ap, int), info);
	else if (type == 'x' || type == 'X' || type == 'u')
		res = ft_print_num(va_arg(ap, unsigned int), info);
	else if (type == 'p')
		res = ft_print_num(va_arg(ap, unsigned long long), info);
	else if (type == '\0')
		res = _ERROR;
	return (res);
}

int	ft_put_prec_num(int len, int i, int res, char **buf)
{
	while (len + i < res)
	{
		(*buf)[i] = '0';
		i++;
	}
	return (i);
}
