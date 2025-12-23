/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:12:01 by nmagamad          #+#    #+#             */
/*   Updated: 2025/12/22 10:20:47 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	free_map(t_game *map)
{
	if (map->north) 
		free(map->north);
	if (map->south)
		free(map->south);
	if (map->east)
		free(map->east);
	if (map->west)
		free(map->west);
	if (map->ceiling)
		free(map->ceiling);
	if (map->floor)
		free(map->floor);
	if (map->map)
		free_tab(map->map);
}

void	free_all(t_game *map)
{
	free_map(map);
}

int	main(int ac, char **av)
{
	t_game	map;

	if (ac != 2)
		return (printf("Error\ntoo few arg\n"));
	if (parse_map_name(av[1]))
		return (printf("Error\nmap is not in .cub\n"));
	if (parsing(av[1], &map))
	{
		free_all(&map);
		return (1);
	}
	free_all(&map);
}
