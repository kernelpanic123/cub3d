/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:46:04 by nmagamad          #+#    #+#             */
/*   Updated: 2025/12/24 06:53:20 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	init_map(t_game *map, char *name)
{
	map->map_name = name;
	map->fd = open(name, O_RDONLY);
	if (map->fd < 0)
		return (printf("Error\nopen failed"));
	close(map->fd);
	map->fd = open(name, O_RDONLY);
	if (map->fd < 0)
		return (printf("Error\nopen failed"));
	close(map->fd);
	map->fd = open(name, O_RDONLY);
	if (map->fd < 0)
		return (printf("Error\nopen failed"));
	close(map->fd);
	return (0);
}
