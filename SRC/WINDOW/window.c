/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:58:05 by abtouait          #+#    #+#             */
/*   Updated: 2025/11/07 22:47:06 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	initialize_window(t_game *data)
{
	int	i;

	i = 0;
	data->win_mlx_ptr = mlx_new_window(data->mlx_ptr,
			(ft_strlen(data->map[i] + 1) * 64), (strlen_array(data->map) * 64), "so_long");
}

void	load_map_img(t_game *data)
{
	int	size;

	size = IMG_SIZE;
	data->img_floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"./SRC/img/sol.xpm", &size, &size);
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./SRC/img/player.xpm", &size, &size);
	data->img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./SRC/img/wall.xpm", &size, &size);
}
void	draw_each_square(t_game *data, char indicator, int x, int y)
{
	void	*img;

	img = NULL;
	if (indicator == '1')
		img = data->img_wall;
	else if (indicator == '0')
		img = data->img_floor;
	else if (indicator == 'N')
		img = data->img_player;
	if (img != NULL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_mlx_ptr, img,
			x * IMG_SIZE, y * IMG_SIZE);
}
void	draw_map(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] != '\0')
				draw_each_square(data, data->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
int main(int argc, char **argv)
{
	(void) argc;
	t_game	data;
	init_var_struct(&data, argv);
	get_map(&data);
	data.mlx_ptr = mlx_init();
	initialize_window(&data);
	load_map_img(&data);
	draw_map(&data);
	mlx_loop(data.mlx_ptr);
}