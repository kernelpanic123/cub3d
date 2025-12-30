/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:11:00 by abtouait          #+#    #+#             */
/*   Updated: 2025/12/30 09:48:55 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	initialize_window(t_game *data)
{
	data->mlx = mlx_init();
	data->screen_w = 1500;
	data->screen_h = 900;
	data->mlx_win = mlx_new_window(data->mlx,
			data->screen_w, data->screen_h, "cub3d");
	data->screen.img = mlx_new_image(data->mlx, data->screen_w, data->screen_h);
	data->screen.addr = mlx_get_data_addr(data->screen.img,
			&data->screen.bits_per_pixel,
			&data->screen.line_length,
			&data->screen.endian);
}

int	init_and_parse(t_game *g, t_ray *r, char *file)
{
	ft_memset(g, 0, sizeof(t_game));
	if (parse_map_name(file))
		return (printf("Error\nmap is not in .cub\n"));
	if (check_empty_map(g, file))
		return (1);
	init_var_struct(g);
	g->ray = r;
	if (parsing(file, g))
	{
		free_all(g);
		return (1);
	}
	initialize_window(g);
	g->screen.width = g->screen_w;
	g->screen.height = g->screen_h;
	load_texture(g, &g->textures[0], g->north);
	load_texture(g, &g->textures[1], g->south);
	load_texture(g, &g->textures[2], g->west);
	load_texture(g, &g->textures[3], g->east);
	init_player(r, g);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	g;
	t_ray	r;

	if (argc != 2)
		return (printf("Error\ntoo few arg\n"));
	if (init_and_parse(&g, &r, argv[1]))
		return (1);
	mlx_hook(g.mlx_win, 2, 1L << 0, wich_input_press, &g);
	mlx_hook(g.mlx_win, 3, 1L << 1, wich_key_release, &g);
	mlx_hook(g.mlx_win, 17, 0, exit_clean, &g);
	mlx_loop_hook(g.mlx, render, &g);
	mlx_loop(g.mlx);
	return (0);
}
