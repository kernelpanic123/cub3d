/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:58:05 by abtouait          #+#    #+#             */
/*   Updated: 2025/11/17 07:52:27 by abtouait         ###   ########.fr       */
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
		printf("Error %s\n", path);
		exit(1);
	}
	tx->addr = mlx_get_data_addr(tx->img,
		&tx->bits_per_pixel, &tx->line_length, &tx->endian);
}

void	draw_tiles(t_texture *screen, t_texture *tx,
							int sx, int sy, int size)
{
	int	x;
	int	y;
	int	tx_x;
	int	tx_y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			tx_x = (x * tx->width) / size;
			tx_y = (y * tx->height) / size;

			my_pixel_put(screen, sx + x, sy + y,
				get_texture_pixel(tx, tx_x, tx_y));
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *g)
{
	int	x;
	int	y;
	int	block;

	block = BLOCK;
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == '1')
				draw_tiles(&g->screen, &g->wall,
					x * block, y * block, block);
			else if (g->map[y][x] == '0')
				draw_tiles(&g->screen, &g->air,
					x * block, y * block, block);
			else if (g->map[y][x] == 'N')
				draw_tiles(&g->screen, &g->player,
					x * block, y * block, block);
			x++;
		}
		y++;
	}
}
void	draw_grid(t_texture *screen, int map_w, int map_h)
{
	int	x;
	int	y;
	int	screen_w = map_w * BLOCK;
	int	screen_h = map_h * BLOCK;

	x = 0;
	while (x <= screen_w)
	{
		y = 0;
		while (y < screen_h)
		{
			my_pixel_put(screen, x, y, 0x000000);
			y++;
		}
		x += BLOCK;
	}
	y = 0;
	while (y <= screen_h)
	{
		x = 0;
		while (x < screen_w)
		{
			my_pixel_put(screen, x, y, 0x000000);
			x++;
		}
		y += BLOCK;
	}
}

int	render(t_game *g)
{
	int w = ft_strlen(g->map[0]) - 1;
	int h = strlen_array(g->map);

	draw_map(g);
	draw_grid(&g->screen, w, h);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->screen.img, 0, 0);
	return (0);
}

void	initialize_window(t_game *data)
{
	data->screen_w = (ft_strlen(data->map[0]) - 1) * BLOCK;
	data->screen_h = strlen_array(data->map) * BLOCK;
	data->mlx_win = mlx_new_window(data->mlx, data->screen_w, data->screen_h, "cub3d");
	data->screen.img = mlx_new_image(data->mlx, data->screen_w, data->screen_h);
	data->screen.addr = mlx_get_data_addr(data->screen.img,
		&data->screen.bits_per_pixel,
		&data->screen.line_length,
		&data->screen.endian);
}

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	t_game	g;

// 	g.mlx = mlx_init();

// 	init_var_struct(&g, argv);
// 	get_map(&g);
// 	replace_space(&g);
// 	get_max_len(&g);
// 	equalize_map(&g);

// 	initialize_window(&g);

// 	load_texture(&g, &g.wall,   "./SRC/img/wall.xpm");
// 	load_texture(&g, &g.air,    "./SRC/img/sol.xpm");
// 	load_texture(&g, &g.player, "./SRC/img/player.xpm");

// 	mlx_loop_hook(g.mlx, render, &g);
// 	mlx_loop(g.mlx);
// 	return (0);
// }
