/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:45:50 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/01/08 09:22:52 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	has_only_redir(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!is_redir(input[i]))
			return (FUNC_FAIL);
		i++;
	}
	return (FUNC_SUC);
}

int	find_special_char(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\\' || input[i] == ';')
			return (FUNC_SUC);
		i++;
	}
	return (FUNC_FAIL);
}

void	check_quote(char c, t_quote *quote)
{
	if (is_quot(c))
	{
		if (quote->is_quoting == 0)
		{
			quote->is_quoting = 1;
			quote->quot = c;
			quote->checked = 1;
		}
		if (quote->is_quoting == 1 && quote->quot == c && quote->checked == 0)
		{
			quote->is_quoting = 0;
			quote->quot = 0;
		}
		quote->checked = 0;
	}
}

int	check_parse_error(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (is_pipe(input[i]) && is_pipe(input[i + 1]))
			return (FUNC_FAIL);
		if (is_redir(input[i]) && is_redir(input[i + 1])
			&& input[i] != input[i + 1])
			return (FUNC_FAIL);
	}
	return (FUNC_SUC);
}

int	check_input(char *input)
{
	t_quote	quote;
	int		i;

	if (find_special_char(input))
		return (ft_strerror_exit("Error: There are unexpected characters\n"));
	i = 0;
	init_quote(&quote);
	while (input[i])
		check_quote(input[i++], &quote);
	if (quote.is_quoting)
		return (ft_strerror_exit("Error: Quotes are not closed\n"));
	if (!check_parse_error(input))
		return (ft_strerror_exit("Error: parse error\n"));
	if (has_only_redir(input))
		return (ft_strerror_exit("minishell: syntax error near unexpected token `newline’\n"));
	return (FUNC_SUC);
}
