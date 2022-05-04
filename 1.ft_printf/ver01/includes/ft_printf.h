/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:33:01 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/01/20 11:50:03 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define	_ERROR	-1

int		ft_printf(const char *str, ...);

int		ft_is_format(char c);
char	*ft_strcadd(char *res, va_list ap);
char	*ft_strsadd(char *res, va_list ap);
void	ft_strncat(char *restrict dst, const char *restrict src,
	size_t start, size_t end);
char	*ft_strnjoin(char *res, const char *str, size_t start, size_t end);

#endif
