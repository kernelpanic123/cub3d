/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cardinals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 01:47:41 by abtouait          #+#    #+#             */
/*   Updated: 2025/11/01 14:03:30 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void get_north(t_game *data)
{
	int i;

	i = 0;
	while (data->file[i] != NULL)
	{
		if (data->file[i][0] == 'N')
			data->north = ft_strdup(data->file[i]);
		i++;
	}
}

void get_west(t_game *data)
{
	int i;

	i = 0;
	while (data->file[i] != NULL)
	{
		if (data->file[i][0] == 'W')
			data->west = ft_strdup(data->file[i]);
		i++;
	}
}

void get_south(t_game *data)
{
	int i;

	i = 0;
	while (data->file[i] != NULL)
	{
		if (data->file[i][0] == 'S')
			data->south = ft_strdup(data->file[i]);
		i++;
	}
}

void get_east(t_game *data)
{
	int i;

	i = 0;
	while (data->file[i] != NULL)
	{
		if (data->file[i][0] == 'E')
			data->east = ft_strdup(data->file[i]);
		i++;
	}
}
