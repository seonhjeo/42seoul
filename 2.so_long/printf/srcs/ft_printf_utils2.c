/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:35:50 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 12:54:41 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		return_prec_or_len(int len, int prec)
{
	if (len < prec)
		return (prec);
	return (len);
}

int		return_prec_or_len2(int prec, int len)
{
	if (prec < len)
		return (prec);
	return (len);
}

char	return_zero_or_space(int zero)
{
	if (zero == 1)
		return ('0');
	return (' ');
}
