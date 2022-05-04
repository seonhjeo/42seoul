/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:24:11 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/11/16 16:52:26 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		ret;

	if (argc != 5 && argc != 6)
		return (write_error("Wrong arguments number"));
	ret = init_all(&rules, argv);
	if (ret)
		return (error_manager(ret));
	if (launcher(&rules))
		return (write_error("Creating threads error"));
	return (0);
}
