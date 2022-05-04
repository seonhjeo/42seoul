/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:20:46 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/03/23 11:46:17 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_width_and_prec(va_list ap, char *str, t_info *info, int i)
{
	if (ft_isdigit(str[i]))
	{
		if (info->prec == -1)
			info->width = info->width * 10 + str[i] - 48;
		else
			info->prec = info->prec * 10 + str[i] - 48;
	}
	else if (str[i] == '*')
	{
		if (info->prec == -1)
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else
			info->prec = va_arg(ap, int);
	}
}

void	ft_check_format(char *str, va_list ap, t_info *info, int i)
{
	if (str[i] == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (str[i] == '-')
		info->minus = 1;
	else if (str[i] == '.')
	{
		if (str[i] != '-')
			info->prec = 0;
		else
			info->prec = -2;
	}
	else if (ft_isdigit(str[i]) || str[i] == '*')
		check_width_and_prec(ap, str, info, i);
}

int	ft_define_format(t_info *info, char *str, va_list ap, int i)
{
	init_info(info);
	while (str[++i] != '\0' && (!ft_strchr(_TYPE, str[i])))
		ft_check_format(str, ap, info, i);
	info->type = str[i++];
	if ((info->minus == 1 || info->prec > -1) && info->type != '%')
		info->zero = 0;
	return (i);
}

int	ft_printf_init(char *str, va_list ap, t_info *info)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
			res += ft_putchar_fd(str[i++], _STDIN);
		if (str[i] == '%')
		{
			i = ft_define_format(info, str, ap, i);
			info->final_len = ft_print_format(ap, info);
			if (info->final_len == _ERROR)
				return (_ERROR);
			res += info->final_len;
		}
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		res;
	t_info	*info;

	if (!str)
		return (_ERROR);
	va_start(ap, str);
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (_ERROR);
	res = ft_printf_init((char *)str, ap, info);
	va_end(ap);
	free(info);
	return (res);
}
