/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:46:04 by nmagamad          #+#    #+#             */
/*   Updated: 2025/12/22 09:48:10 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	init_map(t_game *map, char *name)
{
	map->map_name = name;
	map->ceiling = NULL;
	map->floor = NULL;
	map->north = NULL;
	map->east = NULL;
	map->south = NULL;
	map->west = NULL;
	map->map = NULL;
	map->fd = open(name, O_RDONLY);
	if (map->fd < 0)
		return (printf("Error\nopen failed"));
	init_map2(map);
	close(map->fd);
	map->fd = open(name, O_RDONLY);
	if (map->fd < 0)
		return (printf("Error\nopen failed"));
	init_map3(map);
	close(map->fd);
	map->fd = open(name, O_RDONLY);
	if (map->fd < 0)
		return (printf("Error\nopen failed"));
	init_map4(map);
	close(map->fd);
	return (0);
}
