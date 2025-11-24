/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:09:46 by abtouait          #+#    #+#             */
/*   Updated: 2025/11/21 10:41:30 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	calcul_texture_id(t_ray *r)
{
	if (r->side == 0)
	{
		if (r->stepx > 0)
			r->texture_id = 3; // EAST
		else
			r->texture_id = 2; // WEST
	}
	else
	{
		if (r->stepy > 0)
			r->texture_id = 1; // SOUTH
		else
			r->texture_id = 0; // NORTH
	}
}

void	calculate_texture_coords(t_game *data, t_ray *r)
{
	t_texture	*tex;

	calcul_texture_id(r);
	tex = &data->textures[r->texture_id];
	
	if (r->side == 0)
		r->wallx = r->posy + r->perpwalldist * r->raydiry;
	else
		r->wallx = r->posx + r->perpwalldist * r->raydirx;
	r->wallx -= floor(r->wallx);
	
	r->texx = (int)(r->wallx * (double)tex->width);
	if ((r->side == 0 && r->raydirx > 0) || (r->side == 1 && r->raydiry < 0))
		r->texx = tex->width - r->texx - 1;
	
	r->step = 1.0 * tex->height / r->lineheight;
	r->texpos = (r->drawstart - data->screen_h / 2 + r->lineheight / 2) * r->step;
}
void	draw_wall_textured(t_game *data, t_ray *r)
{
	int			y;
	int			texy;
	int			color;
	t_texture	*tex;

	tex = &data->textures[r->texture_id];
	y = 0;
	while (y < r->drawstart)
	{
		my_pixel_put(&data->screen, r->x, y, 0xFCFF00); // Plafond
		y++;
	}
	while (y <= r->drawend)
	{
		texy = (int)r->texpos;
		if (texy >= tex->height)
			texy = tex->height - 1;
		r->texpos += r->step;
		color = get_texture_pixel(tex, r->texx, texy);
		my_pixel_put(&data->screen, r->x, y, color);
		y++;
	}
	while (y++ < data->screen_h)
		my_pixel_put(&data->screen, r->x, y, 0x800080); // Sol
}


void engine_3d(t_game *g, t_ray *r)
{
	int w;

	w = g->screen_w;
	r->x = 0;
	while (r->x < w)
	{
		
		init_param(g, r);
		dda_loop(g, r);
		calcul_dist_wall(g, r);
		calculate_texture_coords(g, r);
		draw_wall_textured(g, r);
		r->x++;
	}
}

int render(t_game *g)
{
	if (g->w_key)
		move_forward(g);
	if (g->s_key)
		move_backward(g);
	if (g->a_key)
		move_left(g);
	if (g->d_key)
		move_right(g);
	if (g->left_key)
		rotate_left(g);
	if (g->right_key)
		rotate_right(g);
	engine_3d(g, g->ray);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->screen.img, 0, 0);
	return (0);
}
