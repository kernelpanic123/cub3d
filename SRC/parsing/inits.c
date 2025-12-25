/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:46:04 by nmagamad          #+#    #+#             */
/*   Updated: 2025/12/25 13:48:30 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	init_map(t_game *map, char *name)
{
	map->map_name = name;
	map->fd = open(name, O_RDONLY);
	// if (map->fd < 0)
	// 	return (printf("Error\nopen failed"));
	// close(map->fd);
	// map->fd = open(name, O_RDONLY);
	// if (map->fd < 0)
	// 	return (printf("Error\nopen failed"));
	// close(map->fd);
	// map->fd = open(name, O_RDONLY);
	if (map->fd < 0)
		return (printf("Error\nopen failed"));
	close(map->fd);
	return (0);
}
int	parse_color_c2(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ',')
			return (1);
		if ((str[i] == ',' && i == 0)
			|| (str[i] == ',' && ft_isdigit(str[i - 1]))
			|| (str[i] == ',' && ft_isdigit(str[i + 1])))
				return (1);
		if (str[i] == ',')
			count++;
	}
	if (count != 2)
		return (1);
	return (0);
}

int	parse_color_c3(char **tab)
{
	int	rgb[3];

	rgb[0] = ft_atoi(tab[0]);
	rgb[1] = ft_atoi(tab[1]);
	rgb[2] = ft_atoi(tab[2]);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255
		|| rgb[2] < 0 || rgb[2] > 255)
		return (1);
	return (0);
}

int	parse_color_c(t_game *map)
{
	char	*tmp;
	char	**tmp2;

	tmp2 = NULL;
	tmp = ft_strtrim(map->ceiling + 2, " \t\n");
	if (parse_color_c2(tmp))
	{
		free(tmp);
		return (printf ("Error\nColors syntaxe(c1)\n"));
	}
	tmp2 = ft_split(tmp, ',');
	free(tmp);
	if (!tmp2)
		return (printf ("Error\ncolors syntaxe(c5)\n"));
	if (parse_color_c3(tmp2))
	{
		free_tab(tmp2);
		return (printf("Error\ncolors syntaxe(c6)\n"));
	}
	map->c_color = rgb_to_int(map->ceiling);
	free_tab(tmp2);
	return (0);
}
int check_empty_map(t_game *data, char *file)
{
	data->file = parse_map(file);
	if (data->file == NULL)
	{
		printf("ERROR FILE EMPTY\n");
		return (FALSE);
	}
	get_map(data);
	if (!data->map)
	{
		printf("ERROR MAP EMPTY\n");
		free_array_simple(data->file);
		return (FALSE);
	}
	free_array_simple(data->map);
	free_array_simple(data->file);
	return (TRUE);
}
