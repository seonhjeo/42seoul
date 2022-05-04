/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:35:57 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/18 16:33:32 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	israyfacingdown(float angle)
{
	return (angle > 0 && angle < PI);
}

bool	israyfacingup(float angle)
{
	return (!israyfacingdown(angle));
}

bool	israyfacingright(float angle)
{
	return (angle < 0.5 * PI || angle > 1.5 * PI);
}

bool	israyfacingleft(float angle)
{
	return (!israyfacingright(angle));
}

int		get_ray_texture(float rayangle, bool hitvert)
{
	if (hitvert)
	{
		if (israyfacingright(rayangle))
			return (3);
		else
			return (2);
	}
	else
	{
		if (israyfacingup(rayangle))
			return (1);
		else
			return (0);
	}
}
