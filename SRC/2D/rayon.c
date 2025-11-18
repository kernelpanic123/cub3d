/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 08:26:55 by abtouait          #+#    #+#             */
/*   Updated: 2025/11/18 05:07:13 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void get_dir_player(t_ray *r, t_game *data)
{
	int x;
	int y;

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
void get_plan_cam(t_ray *r, t_game *data)
{
	int x;
	int y;

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
	if (data->map[y][x] == 'W')
	{
		r->planx = 0;
		r->plany = -0.66;
	}
	if (data->map[y][x] == 'E')
	{
		r->planx = 0;
		r->plany = 0.66;
	}
}

void get_plan_vector(t_ray *r)
{
	double	x;
	double	y;

	x = r->diry;
	y = -r->dirx;
	r->planx = x * 0.66;
	r->plany = y * 0.66;
}
void get_cameraX(t_ray *r, t_game *data)
{
	r->cameraX = 2 * r->x / (double)data->screen_w - 1;
}

void get_raydir(t_ray *r)
{
	r->raydirx = r->dirx + r->planx * r->cameraX;
	r->raydiry = r->diry + r->plany * r->cameraX;
}

void get_map_pos(t_ray *r)
{
	r->mapx = (int)r->posx;
	r->mapy = (int)r->posy;
}


void init_player(t_ray *r, t_game *data)
{
	r->posx = find_x_player(data) + 0.5;
	r->posy = find_y_player(data) + 0.5;
	get_dir_player(r, data);
	get_plan_cam(r, data);
	get_plan_vector(r);
	
}
void get_deltadist(t_ray *r)
{
	r->deltadistx = abs(1 / r->raydirx);
	r->deltadisty = abs(1 / r->raydiry);
}

int	main(int argc, char **argv)
{
	(void) argc;
	t_game	g;
	t_ray	r;

	g.mlx = mlx_init();

	init_var_struct(&g, argv);
	get_map(&g);
	replace_space(&g);
	get_max_len(&g);
	equalize_map(&g);
	init_player(&r, &g);
	printf("%f\n", r.dirx);
	printf("%f\n", r.diry);
	return (0);
}
