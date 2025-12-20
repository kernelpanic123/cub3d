/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:33:54 by nmagamad          #+#    #+#             */
/*   Updated: 2025/12/17 14:01:44 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_chars(t_map *map)
{
	int	i;
	int	j;
	int	chonteux;

	chonteux = 0;
	j = -1;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] != '0' && map->map[i][j] != '1'
				&& map->map[i][j] != 'E' && map->map[i][j] != 'N'
				&& map->map[i][j] != 'W' && map->map[i][j] != 'S'
				&& map->map [i][j] != ' ' && map->map[i][j] != '\t')
				return (printf("Error\ninvalid char in map\n"));
			if (map->map[i][j] == 'E' || map->map[i][j] == 'N'
			|| map->map[i][j] == 'W' || map->map[i][j] == 'S')
				chonteux++;
		}
	}
	if (chonteux != 1)
		return (printf ("Error\ninvalid char in map\n"));
	return (0);
}

int	parse_card_paths(t_map *map)
{
	char	*tmp;
	int		fd;

	fd = -2;
	tmp = ft_strtrim(map->no + 2, " \t");
	if (ft_strncmp(tmp, "./", 2))
		return (free(tmp), printf("Error\nwrong path for cardinal(s)\n"));
	if (open(tmp + 2, O_RDONLY) < 0)
		return (free(tmp), printf ("Error\nopen failed\n"));
	free(tmp);
	tmp = ft_strtrim(map->so + 2, " \t");
	if (ft_strncmp(tmp, "./", 2))
		return (free(tmp), printf("Error\nwrong path for cardinal(s)\n"));
	if (open(tmp + 2, O_RDONLY) < 0)
		return (free(tmp), printf ("Error\nopen failed\n"));
	free(tmp);
	return (0);
}

int	parse_card_paths2(t_map *map)
{
	char	*tmp;
	int		fd;

	fd = -2;
	tmp = ft_strtrim(map->ea + 2, " \t");
	if (ft_strncmp(tmp, "./", 2))
		return (free(tmp), printf("Error\nwrong path for cardinal(s)\n"));
	if (open(tmp + 2, O_RDONLY) < 0)
		return (free(tmp), printf ("Error\nopen failed\n"));
	free(tmp);
	tmp = ft_strtrim(map->we + 2, " \t");
	if (ft_strncmp(tmp, "./", 2))
		return (free(tmp), printf("Error\nwrong path for cardinal(s)\n"));
	if (open(tmp + 2, O_RDONLY) < 0)
		return (free(tmp), printf ("Error\nopen failed\n"));
	free(tmp);
	return (0);
}

int	check_ifvalid(t_map *map)
{
	if (!map->c)
		return (printf("Error\ncolor init failed\n"));
	if (!map->f)
		return (printf("Error\ncolor init failed\n"));
	if (!map->no)
		return (printf("Error\ncardinal init failed\n"));
	if (!map->so)
		return (printf("Error\ncardinal init failed\n"));
	if (!map->we)
		return (printf("Error\ncardinal init failed\n"));
	if (!map->ea)
		return (printf("Error\ncardinal init failed\n"));
	return (0);
}

int	parsing(char *name, t_map *map)
{
	if (init_map(map, name))
		return (1);
	if (check_ifvalid(map))
		return (1);
	if (parse_chars(map))
		return (1);
	if (parse_color_c(map) || parse_color_f(map))
		return (1);
	if (parse_card_paths(map) || parse_card_paths2(map))
		return (1);
	if (parse_walls(map, ft_tablen(map->map) - 1) || parse_walls2(map))
		return (1);
	return (0);
}
