/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:59:18 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/01/05 09:28:42 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	determine_input_state(char *str, t_quote *quote)
{
	if (is_quot(str[quote->i]) && quote->is_quoting
		&& str[quote->i] == quote->quot && is_word(str, quote->i + 1))
		return (1);
	if (is_quot(str[quote->i]) && quote->is_quoting
		&& str[quote->i] == quote->quot && !is_word(str, quote->i + 1))
		return (2);
	if (is_quot(str[quote->i]) && !quote->is_quoting
		&& is_word(str, quote->i - 1))
		return (3);
	if (is_quot(str[quote->i]) && !quote->is_quoting
		&& !is_word(str, quote->i - 1))
		return (9);
	if (ft_isspace(str[quote->i]) && !quote->is_quoting)
		return (4);
	if (is_pipe(str[quote->i]) && !quote->is_quoting && !quote->is_pipe)
		return (5);
	if (!is_pipe(str[quote->i]) && is_word(str, quote->i + 1)
		&& quote->is_pipe && !quote->is_quoting)
		return (6);
	if (is_redir(str[quote->i]) && !quote->is_quoting && !quote->is_redir)
		return (7);
	if (quote->is_redir && str[quote->i] != quote->redir && !quote->is_quoting)
		return (8);
	return (0);
}

void	tokenize_input_pt(char **buffer,
	t_token **token, t_quote *quote, int flag)
{
	add_token(buffer, token, quote);
	if (flag == 0)
		set_quote(quote, 0, flag);
	else
		set_quote(quote, quote->str[quote->i], flag);
}

void	tokenize_input(char *str, t_token **token, t_quote *quote)
{
	char	*buffer;

	buffer = (char *)malloc(ft_strlen(str) * sizeof(char) + 1);
	while (str[quote->i])
	{
		quote->n = determine_input_state(str, quote);
		if (quote->n == 1)
			set_quote(quote, 0, 0);
		if (quote->n == 2)
			buffer[quote->j++] = str[quote->i++];
		if (quote->n == 2 || quote->n == 4 || quote->n == 6 || quote->n == 8)
			tokenize_input_pt(&buffer, token, quote, 0);
		if (quote->n == 9)
			tokenize_input_pt(&buffer, token, quote, 1);
		if (quote->n == 3)
			set_quote(quote, str[quote->i], 1);
		if (quote->n == 5)
			tokenize_input_pt(&buffer, token, quote, 3);
		if (quote->n == 7)
			tokenize_input_pt(&buffer, token, quote, 2);
		buffer[quote->j++] = str[quote->i++];
		quote->checked = 0;
	}
	add_token(&buffer, token, quote);
	free(buffer);
}

void	free_token(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp != NULL)
	{
		token = token->next;
		free(temp);
		temp = token;
	}
}

int	init_token(char *input, t_token *token)
{
	t_quote	quote;

	token = NULL;
	init_quote(&quote);
	quote.str = input;
	tokenize_input(input, &token, &quote);
	treeing_input(token);
	free_token(token);
	if (g_data.error_code != -1)
		return (FUNC_FAIL);
	return (FUNC_SUC);
}
