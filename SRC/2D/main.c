/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:11:00 by abtouait          #+#    #+#             */
/*   Updated: 2025/11/22 13:47:07 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	initialize_window(t_game *data)
{
	data->mlx = mlx_init();
	data->screen_w = 1500;
	data->screen_h = 900;
	data->mlx_win = mlx_new_window(data->mlx, data->screen_w, data->screen_h, "cub3d");
	data->screen.img = mlx_new_image(data->mlx, data->screen_w, data->screen_h);
	data->screen.addr = mlx_get_data_addr(data->screen.img,
		&data->screen.bits_per_pixel,
		&data->screen.line_length,
		&data->screen.endian);
}

// int main(int argc, char **argv)
// {
// 	t_game  g;
// 	t_ray   r;

// 	(void) argc;
// 	g.ray = &r;
// 	init_var_struct(&g, argv);
// 	get_map(&g);
// 	replace_space(&g);
// 	get_max_len(&g);
// 	equalize_map(&g);
// 	initialize_window(&g);
// 	g.screen.width = g.screen_w;
// 	g.screen.height = g.screen_h;
// 	load_texture(&g, &g.textures[0], "./SRC/img/sud.xpm"); // NORTH
// 	load_texture(&g, &g.textures[1], "./SRC/img/wall.xpm"); // SOUTH
// 	load_texture(&g, &g.textures[2], "./SRC/img/wall.xpm");  // WEST
// 	load_texture(&g, &g.textures[3], "./SRC/img/wall.xpm");  // EAST
	
// 	init_player(&r, &g);
// 	mlx_hook(g.mlx_win, 2, 1L << 0, wich_input_press, &g);
// 	mlx_hook(g.mlx_win, 3, 1L << 1, wich_key_release, &g);
// 	mlx_loop_hook(g.mlx, render, &g);
// 	mlx_loop(g.mlx);
// 	return (0);
// }
