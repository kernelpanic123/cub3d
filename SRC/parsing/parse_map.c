/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:33:54 by nmagamad          #+#    #+#             */
/*   Updated: 2025/12/22 10:50:44 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	parse_card_paths(t_game *map)
{
	char	*tmp;
	int		fd;

	fd = -2;
	tmp = ft_strtrim(map->north + 2, " \t");
	if (ft_strncmp(tmp, "./", 2))
		return (free(tmp), printf("Error\nwrong path for cardinal(s)\n"));
	if (open(tmp + 2, O_RDONLY) < 0)
		return (free(tmp), printf ("Error\nopen failed\n"));
	free(tmp);
	tmp = ft_strtrim(map->south + 2, " \t");
	if (ft_strncmp(tmp, "./", 2))
		return (free(tmp), printf("Error\nwrong path for cardinal(s)\n"));
	if (open(tmp + 2, O_RDONLY) < 0)
		return (free(tmp), printf ("Error\nopen failed\n"));
	free(tmp);
	return (0);
}

int	parse_card_paths2(t_game *map)
{
	char	*tmp;
	int		fd;

	fd = -2;
	tmp = ft_strtrim(map->east + 2, " \t");
	if (ft_strncmp(tmp, "./", 2))
		return (free(tmp), printf("Error\nwrong path for cardinal(s)\n"));
	if (open(tmp + 2, O_RDONLY) < 0)
		return (free(tmp), printf ("Error\nopen failed\n"));
	free(tmp);
	tmp = ft_strtrim(map->west + 2, " \t");
	if (ft_strncmp(tmp, "./", 2))
		return (free(tmp), printf("Error\nwrong path for cardinal(s)\n"));
	if (open(tmp + 2, O_RDONLY) < 0)
		return (free(tmp), printf ("Error\nopen failed\n"));
	free(tmp);
	return (0);
}

int	check_ifvalid(t_game *map)
{
	if (!map->ceiling)
		return (printf("Error\ncolor init failed\n"));
	if (!map->floor)
		return (printf("Error\ncolor init failed\n"));
	if (!map->north)
		return (printf("Error\ncardinal init failed\n"));
	if (!map->south)
		return (printf("Error\ncardinal init failed\n"));
	if (!map->west)
		return (printf("Error\ncardinal init failed\n"));
	if (!map->east)
		return (printf("Error\ncardinal init failed\n"));
	return (0);
}

int	parsing(char *name, t_game *map)
{
	if (init_map(map, name))
		return (1);
	if (check_ifvalid(map))
		return (1);
	if (parse_chars(map))
		return (1);
	if (parse_rgb(map))
		return (1);
	if (parse_card_paths(map) || parse_card_paths2(map))
		return (1);
	if (parse_walls(map, ft_tablen(map->map) - 1) || parse_walls2(map))
		return (1);
	return (0);
}
