/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:23:36 by abtouait          #+#    #+#             */
/*   Updated: 2025/11/04 19:30:11 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void get_floor(t_game *data)
{
	int i;

	i = 0;
	while (data->file[i] != NULL)
	{
		if (data->file[i][0] == 'F')
			data->floor = ft_strdup(data->file[i]);
		i++;
	}
}
void get_ceiling(t_game *data)
{
	int i;

	i = 0;
	while (data->file[i] != NULL)
	{
		if (data->file[i][0] == 'C')
			data->ceiling = ft_strdup(data->file[i]);
		i++;
	}
}
