/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:33:54 by nmagamad          #+#    #+#             */
/*   Updated: 2025/12/27 09:35:40 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	parse_card_paths(t_game *map)
{
	char	*tmp;

	tmp = ft_strtrim(map->north + 2, " \t\n");
	if (ft_strncmp(tmp, "./", 2))
	{
		printf("%s\n", tmp);
		return (free(tmp), printf("Error\nwrong path for cardinal(s)\n"));
	}
	if (open(tmp, O_RDONLY) < 0)
	{
		printf("%s\n", tmp);
		return (free(tmp), printf ("Error1\nopen failed\n"));
	}
	free(tmp);
	tmp = ft_strtrim(map->south + 2, " \t\n");
	if (ft_strncmp(tmp, "./", 2))
		return (free(tmp), printf("Error\nwrong path for cardinal(s)\n"));
	if (open(tmp, O_RDONLY) < 0)
		return (free(tmp), printf ("Error2\nopen failed\n"));
	free(tmp);
	return (0);
}

int	parse_card_paths2(t_game *map)
{
	char	*tmp;

	tmp = ft_strtrim(map->east + 2, " \t\n");
	if (ft_strncmp(tmp, "./", 2))
		return (free(tmp), printf("Error\nwrong path for cardinal(s)\n"));
	if (open(tmp, O_RDONLY) < 0)
		return (free(tmp), printf ("Error\nopen failed\n"));
	free(tmp);
	tmp = ft_strtrim(map->west + 2, " \t\n");
	if (ft_strncmp(tmp, "./", 2))
		return (free(tmp), printf("Error\nwrong path for cardinal(s)\n"));
	if (open(tmp, O_RDONLY) < 0)
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
	if (!map->map)
		return (printf("Error\nmap init failed\n"));
	return (0);
}

int	parsing(char *name, t_game *map)
{
	if (init_map(map, name))
		return (1);
	if (check_ifvalid(map))
		return (1);
	if (check_char_map(map))
		return (1);
	if (parse_color_c(map) || parse_color_f(map))
		return (1);
	if (parse_player(map) != 1)
	{
		printf("ERROR NO OR MORE THAN 1 PLAYER DETECTED\n");
		return (FALSE);
	}
	if (parse_card_paths(map) || parse_card_paths2(map))
		return (1);
	if (check_closed_map(map))
	{
		printf("MAP NOT CLOSE\n");
		return (1);
	}
	get_exact_path(map);
	return (0);
}

void	get_exact_path(t_game *data)
{
	char	*tmp;

	tmp = ft_strtrim(data->east + 2, " \t\n");
	free(data->east);
	data->east = tmp;
	tmp = ft_strtrim(data->north + 2, " \t\n");
	free(data->north);
	data->north = tmp;
	tmp = ft_strtrim(data->south + 2, " \t\n");
	free(data->south);
	data->south = tmp;
	tmp = ft_strtrim(data->west + 2, " \t\n");
	free(data->west);
	data->west = tmp;
}
