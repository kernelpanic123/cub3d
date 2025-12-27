/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cardinals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 01:47:41 by abtouait          #+#    #+#             */
/*   Updated: 2025/12/26 11:42:26 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	get_north(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file[i] != NULL)
	{
		j = 0;
		while (data->file[i][j] == ' ')
			j++;
		if (data->file[i][j] == 'N')
			data->north = ft_strdup(data->file[i]);
		i++;
	}
}

void	get_west(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file[i] != NULL)
	{
		j = 0;
		while (data->file[i][j] == ' ')
			j++;
		if (data->file[i][j] == 'W')
			data->west = ft_strdup(data->file[i]);
		i++;
	}
}

void	get_south(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file[i] != NULL)
	{
		j = 0;
		while (data->file[i][j] == ' ')
			j++;
		if (data->file[i][j] == 'S')
			data->south = ft_strdup(data->file[i]);
		i++;
	}
}

void	get_east(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file[i] != NULL)
	{
		j = 0;
		while (data->file[i][j] == ' ')
			j++;
		if (data->file[i][j] == 'E')
			data->east = ft_strdup(data->file[i]);
		i++;
	}
}
