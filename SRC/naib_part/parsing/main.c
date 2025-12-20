/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:12:01 by nmagamad          #+#    #+#             */
/*   Updated: 2025/12/17 13:32:16 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	if (map->no) 
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->ea)
		free(map->ea);
	if (map->we)
		free(map->we);
	if (map->c)
		free(map->c);
	if (map->f)
		free(map->f);
	if (map->map)
		free_tab(map->map);
}

void	free_all(t_map *map)
{
	free_map(map);
}

int	main(int ac, char **av)
{
	t_map	map;

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
