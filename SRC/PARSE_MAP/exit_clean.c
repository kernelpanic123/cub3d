/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:05:32 by abtouait          #+#    #+#             */
/*   Updated: 2025/12/26 11:43:52 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	exit_clean(t_game *data)
{
	int	i;

	i = 0;
	if (data->screen.img)
		mlx_destroy_image(data->mlx, data->screen.img);
	while (i < 4)
	{
		if (data->textures[i].img)
			mlx_destroy_image(data->mlx, data->textures[i].img);
		i++;
	}
	if (data->mlx && data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit_clean_char(data);
	return (0);
}

void	exit_clean_char(t_game *data)
{
	free(data->floor);
	free(data->ceiling);
	free(data->north);
	free(data->south);
	free(data->west);
	free(data->east);
	if (data->map)
		free_array_simple(data->map);
	if (data->file)
		free_array_simple(data->file);
}
