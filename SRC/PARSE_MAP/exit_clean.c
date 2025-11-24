/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:05:32 by abtouait          #+#    #+#             */
/*   Updated: 2025/11/24 18:31:26 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int exit_clean(t_game *data)
{
	free(data->floor);
	free(data->ceiling);
	free(data->north);
	free(data->west);
	free(data->south);
	free(data->east);
	free_array_simple(data->map);
	free_array_simple(data->file);
	mlx_destroy_image(data->mlx, data->screen.img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	 if (data->screen.img)
		mlx_destroy_image(data->mlx, data->screen.img);
	if (data->mlx && data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	return (0);
}
