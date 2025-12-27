/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:21:47 by abtouait          #+#    #+#             */
/*   Updated: 2025/12/26 12:05:41 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	my_pixel_put(t_texture *tx, int x, int y, int color)
{
	char	*dst;

	dst = tx->addr + (y * tx->line_length + x * (tx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_texture_pixel(t_texture *tx, int x, int y)
{
	char	*pixel;

	pixel = tx->addr + (y * tx->line_length + x * (tx->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

void	load_texture(t_game *g, t_texture *tx, char *path)
{
	tx->img = mlx_xpm_file_to_image(g->mlx, path, &tx->width, &tx->height);
	if (!tx->img)
	{
		printf("Error texture %s\n", path);
		exit(1);
	}
	tx->addr = mlx_get_data_addr(tx->img,
			&tx->bits_per_pixel, &tx->line_length, &tx->endian);
}
