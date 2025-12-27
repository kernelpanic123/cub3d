/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 08:26:55 by abtouait          #+#    #+#             */
/*   Updated: 2025/12/26 11:10:31 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	get_dir_player(t_ray *r, t_game *data)
{
	int	x;
	int	y;

	x = find_x_player(data);
	y = find_y_player(data);
	if (data->map[y][x] == 'N')
	{
		r->dirx = 0;
		r->diry = -1;
	}
	if (data->map[y][x] == 'S')
	{
		r->dirx = 0;
		r->diry = 1;
	}
	if (data->map[y][x] == 'W')
	{
		r->dirx = -1;
		r->diry = 0;
	}
	if (data->map[y][x] == 'E')
	{
		r->dirx = 1;
		r->diry = 0;
	}
}

void	get_plan_cam(t_ray *r, t_game *data)
{
	int	x;
	int	y;

	x = find_x_player(data);
	y = find_y_player(data);
	if (data->map[y][x] == 'N')
	{
		r->planx = 0.66;
		r->plany = 0;
	}
	if (data->map[y][x] == 'S')
	{
		r->planx = -0.66;
		r->plany = 0;
	}
	if (data->map[y][x] == 'E')
	{
		r->planx = 0;
		r->plany = 0.66;
	}
	if (data->map[y][x] == 'W')
	{
		r->planx = 0;
		r->plany = -0.66;
	}
}

void	get_map_pos(t_ray *r)
{
	r->mapx = (int)r->posx;
	r->mapy = (int)r->posy;
}

void	init_player(t_ray *r, t_game *data)
{
	r->posx = find_x_player(data) + 0.5;
	r->posy = find_y_player(data) + 0.5;
	get_dir_player(r, data);
	get_plan_cam(r, data);
	get_map_pos(r);
	data->a_key = 0;
	data->s_key = 0;
	data->d_key = 0;
	data->w_key = 0;
	data->left_key = 0;
	data->right_key = 0;
}
