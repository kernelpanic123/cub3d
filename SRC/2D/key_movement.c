/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 08:13:37 by abtouait          #+#    #+#             */
/*   Updated: 2025/12/26 11:17:11 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	move_backward(t_game *g)
{
	double	speed;
	double	next_x;
	double	next_y;

	speed = 0.1;
	next_x = g->ray->posx - g->ray->dirx * speed;
	next_y = g->ray->posy - g->ray->diry * speed;
	if (is_valid_position(g, next_x, next_y))
	{
		g->ray->posx = next_x;
		g->ray->posy = next_y;
	}
}

void	move_right(t_game *g)
{
	double	speed;
	double	px;
	double	py;
	double	next_x;
	double	next_y;

	speed = 0.1;
	px = -g->ray->diry;
	py = g->ray->dirx;
	next_x = g->ray->posx + px * speed;
	next_y = g->ray->posy + py * speed;
	if (is_valid_position(g, next_x, next_y))
	{
		g->ray->posx = next_x;
		g->ray->posy = next_y;
	}
}

void	move_left(t_game *g)
{
	double	speed;
	double	px;
	double	py;
	double	next_x;
	double	next_y;

	speed = 0.1;
	px = g->ray->diry;
	py = -g->ray->dirx;
	next_x = g->ray->posx + px * speed;
	next_y = g->ray->posy + py * speed;
	if (is_valid_position(g, next_x, next_y))
	{
		g->ray->posx = next_x;
		g->ray->posy = next_y;
	}
}

void	rotate_left(t_game *g)
{
	double	rotspeed;
	double	olddirx;
	double	oldplanex;

	rotspeed = 0.03;
	olddirx = g->ray->dirx;
	oldplanex = g->ray->planx;
	g->ray->dirx = g->ray->dirx
		* cos(-rotspeed) - g->ray->diry * sin(-rotspeed);
	g->ray->diry = olddirx * sin(-rotspeed) + g->ray->diry * cos(-rotspeed);
	g->ray->planx = g->ray->planx
		* cos(-rotspeed) - g->ray->plany * sin(-rotspeed);
	g->ray->plany = oldplanex * sin(-rotspeed) + g->ray->plany * cos(-rotspeed);
}

void	rotate_right(t_game *g)
{
	double	rotspeed;
	double	olddirx;
	double	oldplanex;

	rotspeed = 0.03;
	olddirx = g->ray->dirx;
	oldplanex = g->ray->planx;
	g->ray->dirx = g->ray->dirx * cos(rotspeed) - g->ray->diry * sin(rotspeed);
	g->ray->diry = olddirx * sin(rotspeed) + g->ray->diry * cos(rotspeed);
	g->ray->planx = g->ray->planx
		* cos(rotspeed) - g->ray->plany * sin(rotspeed);
	g->ray->plany = oldplanex * sin(rotspeed) + g->ray->plany * cos(rotspeed);
}
