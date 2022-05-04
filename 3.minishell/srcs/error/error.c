/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:02:20 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/01/07 17:36:13 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strerror_exit(char *errstr)
{
	ft_putstr_fd(errstr, STDERR);
	return (FUNC_FAIL);
}

void	ft_builtin_err(char *str1, char *str2, int errnum)
{
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(str1, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(str2, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(strerror(errnum), STDERR);
	ft_putstr_fd("\n", STDERR);
	g_data.exit_code = 1;
}

void	ft_redirection_err(char *str, int errnum)
{
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(str, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(strerror(errnum), STDERR);
	ft_putstr_fd("\n", STDERR);
	g_data.exit_code = 1;
}

void ft_custom_err(char *str1, char *str2)
{
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(str1, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(str2, STDERR);
	ft_putstr_fd("\n", STDERR);
	g_data.exit_code = 1;
}

void ft_custom_err2(char *str1, char *str2, char *str3)
{
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(str1, STDERR);
	ft_putstr_fd(str2, STDERR);
	ft_putstr_fd(str3, STDERR);
	ft_putstr_fd("\n", STDERR);
	g_data.exit_code = 1;
}