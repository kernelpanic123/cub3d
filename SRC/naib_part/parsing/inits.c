/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:46:04 by nmagamad          #+#    #+#             */
/*   Updated: 2025/12/17 13:51:10 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	replace_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
		{
			str[i++] = '1';
			str[i++] = '1';
			str[i++] = '1';
			str[i] = '1';
		}
		i++;
	}
}

int	custom_strlen(char *str)
{
	int	i;
	int	add;

	add = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			add += 3;
		i++;
	}
	return (i + add);
}

char	*ft_copy(char *line)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(custom_strlen(line) + 1);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '\t')
		{
			res[j++] = '1';
			res[j++] = '1';
			res[j++] = '1';
			res[j++] = '1';
		}
		else if (line[i] == ' ')
			res[j++] = '1';
		else
			res[j++] = line[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}

void	init_map4(t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	map->map = malloc(sizeof(char *) * (map_count_line(map->map_name) + 1));
	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		if (*line != '\n'
			&& *line != 'F' && *line != 'C' && *line != 'E'
			&& *line != 'N' && *line != 'S' && *line != 'W')
			map->map[i++] = ft_copy(line);
		free(line);
	}
	map->map[i] = NULL;
}

int	init_map(t_map *map, char *name)
{
	map->map_name = name;
	map->c = NULL;
	map->f = NULL;
	map->no = NULL;
	map->ea = NULL;
	map->so = NULL;
	map->we = NULL;
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
