/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:33:01 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/03/23 12:13:10 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define _ERROR -1
# define _STDIN 1
# define _TYPE "cspdiuxX%"

typedef struct s_info
{
	int			minus;
	int			zero;
	int			width;
	int			prec;
	char		type;
	int			nbr_base;
	int			nbr_sign;
	int			final_len;
}				t_info;

int				ft_printf(const char *str, ...);

int				ft_printf_init(char *str, va_list ap, t_info *info);
int				ft_define_format(t_info *info, char *str, va_list ap, int i);
void			ft_check_format(char *str, va_list ap, t_info *info, int i);
void			check_width_and_prec(va_list ap,
					char *str, t_info *info, int i);

int				ft_print_format(va_list ap, t_info *info);
char			*ft_return_base(char type);
int				ft_check_len_num(unsigned long long num, t_info *info);
void			init_info(t_info *info);

int				return_prec_or_len(int len, int prec);
int				return_prec_or_len2(int prec, int len);
char			return_zero_or_space(int zero);

int				ft_print_char(char c, t_info *info);
int				ft_print_width_c(int width, int len, int zero);

int				ft_print_str(char *str, t_info *info);
int				ft_add_width_str(char **buf, t_info *info);
char			*ft_prec_buf_str(char *str, int prec, int len);

int				ft_print_num(unsigned long long num, t_info *info);
int				ft_put_prec_num(int len, int i, int res, char **buf);
int				ft_prec_buf_num(unsigned long long num,
					t_info *info, char **buf);
int				add_minus(t_info *info, char **buf);
int				add_minus2(int len, t_info *info, char **buf);
int				ft_add_pointer_prefix(char **buf);

#endif
