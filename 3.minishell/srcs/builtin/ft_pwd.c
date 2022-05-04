/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:49:45 by hyenam            #+#    #+#             */
/*   Updated: 2022/01/04 18:18:18 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_pwd()
{
    char path[BUFFER_SIZE];

    ft_putstr_fd(getcwd(path, BUFFER_SIZE), STDOUT);
    ft_putstr_fd("\n", STDOUT);
    g_data.exit_code = 0;
}