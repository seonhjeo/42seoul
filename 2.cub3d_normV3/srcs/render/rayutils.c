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

bool	isRayFacingDown(float angle)
{
	return (angle > 0 && angle < PI);
}

bool	isRayFacingUp(float angle)
{
	return (!isRayFacingDown(angle));
}

bool	isRayFacingRight(float angle)
{
	return (angle < 0.5 * PI || angle > 1.5 * PI);
}

bool	isRayFacingLeft(float angle)
{
	return (!isRayFacingRight(angle));
}

int	get_ray_texture(float rayangle, bool hitvert)
{
	if (hitvert)
	{
		if (isRayFacingRight(rayangle))
			return (3);
		else
			return (2);
	}
	else
	{
		if (isRayFacingUp(rayangle))
			return (1);
		else
			return (0);
	}
}
