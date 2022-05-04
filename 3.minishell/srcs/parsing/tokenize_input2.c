/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_input2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 11:51:31 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/01/05 09:24:42 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_token_env(t_token_env *env)
{
	env->env = NULL;
	env->env_value = NULL;
	env->buff = NULL;
	env->is_env = 0;
	env->start = 0;
	env->end = 0;
	env->i = -1;
}

void	change_env_to_value_pt(char *temp, t_token_env *t_env, int flag)
{
	if (flag == 0)
	{
		t_env->buff = get_env_data(&temp[1]);
		if (!t_env->env_value)
			t_env->env_value = ft_strdup("");
	}
	if (flag == 1)
	{
		t_env->env = ft_strndup(&temp[t_env->start], t_env->i - t_env->start);
		t_env->env_value = get_env_data(&t_env->env[1]);
		if (!t_env->env_value)
			t_env->env_value = ft_strdup("");
		t_env->buff = ft_strjoin_token(t_env->buff, t_env->env_value);
		free(t_env->env);
		free(t_env->env_value);
	}
	if (flag == 2)
	{
		t_env->env = ft_strndup(&temp[t_env->end], t_env->i - t_env->end);
		t_env->buff = ft_strjoin_token(t_env->buff, t_env->env);
		free(t_env->env);
		t_env->start = t_env->i;
		t_env->is_env = 1;
	}
}

char	*change_env_to_value(char *temp, int flag)
{
	t_token_env	t_env;

	init_token_env(&t_env);
	if (flag == T_ENVP)
		change_env_to_value_pt(temp, &t_env, 0);
	else
	{
		while (temp[++t_env.i])
		{
			if (t_env.is_env && (ft_isspace(temp[t_env.i])
					|| is_quot(temp[t_env.i]) || temp[t_env.i] == '$'))
			{
				t_env.end = t_env.i;
				change_env_to_value_pt(temp, &t_env, 1);
				t_env.is_env = 0;
			}
			if (temp[t_env.i] == '$')
				change_env_to_value_pt(temp, &t_env, 2);
		}
		change_env_to_value_pt(temp, &t_env, 2);
	}
	return (t_env.buff);
}

int	check_token_type(char *temp)
{
	t_token_env	t_env;

	init_token_env(&t_env);
	if (is_redir(temp[0]))
		return (T_REDIRECT);
	if (is_pipe(temp[0]))
		return (T_PIPE);
	while (temp[++t_env.i])
	{
		if (temp[t_env.i] == '$')
			t_env.end = 1;
		if (temp[t_env.i] == '\'')
			t_env.start = 1;
		if (temp[t_env.i] == '\"')
			t_env.start = 2;
	}
	if (t_env.start == 1)
		return (T_SINGLE_QUOTES);
	if (t_env.start == 2 && t_env.end)
		return (T_ENVP_DQUOTES);
	else if (t_env.start == 2)
		return (T_DOUBLE_QUOTES);
	else if (t_env.end)
		return (T_ENVP);
	return (T_WORD);
}

void	add_token(char **buffer, t_token **token, t_quote *quote)
{
	int		t_type;
	char	*temp;
	int		res;

	(*buffer)[quote->j] = '\0';
	if (!only_has_space((*buffer)))
	{
		temp = ft_strtrim((*buffer), " ");
		if (!temp)
			g_data.exit_code = 1;
		t_type = check_token_type(temp);
		if (t_type == T_ENVP || t_type == T_ENVP_DQUOTES)
			temp = change_env_to_value(temp, t_type);
		if (t_type == T_DOUBLE_QUOTES || t_type == T_SINGLE_QUOTES
			|| t_type == T_ENVP_DQUOTES)
			temp = delete_quote(temp);
		res = add_token_back(token, t_type, temp);
		if (!res)
			g_data.error_code = 12;
		quote->j = 0;
	}
}
