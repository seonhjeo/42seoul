/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:21:36 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/01/08 09:15:32 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_parsing(char	*input)
{
	t_token	p_token;

	if (!check_input(input))
	{
		g_data.error_code = 1;
		return ;
	}
	else
		init_token(input, &p_token);
}

int	get_command(char **input)
{
	char		*trim;
	static char	*str;

	*input = readline(ft_strjoin(getcwd(str, BUFFER_SIZE), " > "));
	if (*input)
	{
		add_history(*input);
		trim = ft_strtrim(*input, " ");
		if (trim)
		{
			free(*input);
			do_parsing(trim);
			free(trim);
		}
		else
			g_data.error_code = 12;
	}
	else
	{
		ft_putstr_fd("\b\bexit\n", STDOUT);
		g_data.error_code = CTRL_D;
	}
	free(str);
	return (FUNC_SUC);
}
