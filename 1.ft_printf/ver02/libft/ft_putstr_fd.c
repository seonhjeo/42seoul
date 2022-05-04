/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:40:43 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/03/23 11:19:42 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_fd(char *str, int fd)
{
	size_t	n;

	if (!str)
		return (0);
	n = ft_strlen(str);
	write(fd, str, n);
	return (n);
}
