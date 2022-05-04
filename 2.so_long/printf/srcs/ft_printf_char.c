/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:16:18 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/03/23 11:46:47 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_char(char c, t_info *info)
{
	int		res;

	res = 0;
	if (info->type == '%' && info->minus == 1)
		info->zero = 0;
	if (info->minus == 1)
		res += ft_putchar_fd(c, _STDIN);
	res += ft_print_width_c(info->width, 1, info->zero);
	if (info->minus == 0)
		res += ft_putchar_fd(c, _STDIN);
	return (res);
}

int	ft_print_width_c(int width, int len, int zero)
{
	int		res;

	res = 0;
	while (len < width)
	{
		if (zero == 1)
			res += ft_putchar_fd('0', _STDIN);
		else
			res += ft_putchar_fd(' ', _STDIN);
		len++;
	}
	return (res);
}
