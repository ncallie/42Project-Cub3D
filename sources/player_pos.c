/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:20:56 by ncallie           #+#    #+#             */
/*   Updated: 2022/04/07 18:20:57 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void
	init_ray(t_info *info, int i, int j)
{
	info->ray.posX = i + 0.5;
	info->ray.posY = j + 0.5;
	info->ray.dirX = 0;
	info->ray.dirY = 0;
	info->ray.planeX = 0;
	info->ray.planeY = 0;
}

void
	player_pos(t_info *info, int i, int j)
{
	info->ray.posX = i + 0.5;
	info->ray.posY = j + 0.5;
	if (info->map[i][j] == 'E')
	{
		info->ray.dirY = 1;
		info->ray.planeX = 0.66;
	}
	else if (info->map[i][j] == 'W')
	{
		info->ray.dirY = -1;
		info->ray.planeX = -0.66;
	}
	else if (info->map[i][j] == 'S')
	{
		info->ray.dirX = 1;
		info->ray.planeY = -0.66;
	}
	else if (info->map[i][j] == 'N')
	{
		info->ray.dirX = -1;
		info->ray.planeY = 0.66;
	}
}
