/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:08:34 by abtouait          #+#    #+#             */
/*   Updated: 2025/12/27 10:03:08 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	dda_loop(t_game *data, t_ray *r)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (r->sidedistx < r->sidedisty)
		{
			r->sidedistx += r->deltadistx;
			r->mapx += r->stepx;
			r->side = 0;
		}
		else
		{
			r->sidedisty += r->deltadisty;
			r->mapy += r->stepy;
			r->side = 1;
		}
		if (data->map[r->mapy][r->mapx] == '1')
			hit = 1;
	}
}

void	init_param2(t_ray *r)
{
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->sidedistx = (r->posx - r->mapx) * r->deltadistx;
	}
	else
	{
		r->stepx = 1;
		r->sidedistx = (r->mapx + 1.0 - r->posx) * r->deltadistx;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->sidedisty = (r->posy - r->mapy) * r->deltadisty;
	}
	else
	{
		r->stepy = 1;
		r->sidedisty = (r->mapy + 1.0 - r->posy) * r->deltadisty;
	}
}

void	init_param(t_game *data, t_ray *r)
{
	int	w;

	w = data->screen_w;
	r->camerax = 2 * r->x / (double)w - 1;
	r->raydirx = r->dirx + r->planx * r->camerax;
	r->raydiry = r->diry + r->plany * r->camerax;
	r->mapx = (int)r->posx;
	r->mapy = (int)r->posy;
	if (r->raydirx == 0)
		r->deltadistx = 1e30;
	else
		r->deltadistx = fabs(1.0 / r->raydirx);
	if (r->raydiry == 0)
		r->deltadisty = 1e30;
	else
		r->deltadisty = fabs(1.0 / r->raydiry);
	init_param2(r);
}

void	calcul_dist_wall(t_game *data, t_ray *r)
{
	if (r->side == 0)
		r->perpwalldist = r->sidedistx - r->deltadistx;
	else
		r->perpwalldist = r->sidedisty - r->deltadisty;
	r->lineheight = (int)(data->screen_h / r->perpwalldist);
	r->drawstart = -r->lineheight / 2 + data->screen_h / 2;
	if (r->drawstart < 0)
		r->drawstart = 0;
	r->drawend = r->lineheight / 2 + data->screen_h / 2;
	if (r->drawend >= data->screen_h)
		r->drawend = data->screen_h - 1;
}
