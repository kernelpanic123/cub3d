/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:02:38 by abtouait          #+#    #+#             */
/*   Updated: 2025/12/26 11:06:34 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	wich_input_press(int keysim, t_game *data)
{
	if (keysim == XK_Escape)
	{
		exit_clean(data);
		exit(1);
	}
	if (keysim == XK_w)
		data->w_key = 1;
	if (keysim == XK_d)
		data->d_key = 1;
	if (keysim == XK_s)
		data->s_key = 1;
	if (keysim == XK_a)
		data->a_key = 1;
	if (keysim == XK_Left)
		data->left_key = 1;
	if (keysim == XK_Right)
		data->right_key = 1;
	return (0);
}

int	wich_key_release(int keysim, t_game *data)
{
	if (keysim == XK_w)
		data->w_key = 0;
	if (keysim == XK_d)
		data->d_key = 0;
	if (keysim == XK_s)
		data->s_key = 0;
	if (keysim == XK_a)
		data->a_key = 0;
	if (keysim == XK_Left)
		data->left_key = 0;
	if (keysim == XK_Right)
		data->right_key = 0;
	return (0);
}

int	is_valid_position(t_game *g, double x, double y)
{
	double	hitbox;

	hitbox = 0.2;
	if (g->map[(int)(y - hitbox)][(int)(x - hitbox)] == '1')
		return (0);
	if (g->map[(int)(y - hitbox)][(int)(x + hitbox)] == '1')
		return (0);
	if (g->map[(int)(y + hitbox)][(int)(x - hitbox)] == '1')
		return (0);
	if (g->map[(int)(y + hitbox)][(int)(x + hitbox)] == '1')
		return (0);
	return (1);
}

void	move_forward(t_game *g)
{
	double	speed;
	double	next_x;
	double	next_y;

	speed = 0.1;
	next_x = g->ray->posx + g->ray->dirx * speed;
	next_y = g->ray->posy + g->ray->diry * speed;
	if (is_valid_position(g, next_x, next_y))
	{
		g->ray->posx = next_x;
		g->ray->posy = next_y;
	}
}
