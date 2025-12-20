/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:08:41 by nmagamad          #+#    #+#             */
/*   Updated: 2025/12/17 13:09:22 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map2(t_map *map)
{
	char	*res;
	char	*line;

	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		if (*line == '\n')
		{
			free(line);
			continue ;
		}
		res = ft_strtrim(line, " \t\n");
		free(line);
		if (ft_strncmp(res, "NO", 2) == 0)
			map->no = ft_strdup(res);
		else if (ft_strncmp(res, "SO", 2) == 0)
			map->so = ft_strdup(res);
		else if (ft_strncmp(res, "EA", 2) == 0)
			map->ea = ft_strdup(res);
		else if (ft_strncmp(res, "WE", 2) == 0)
			map->we = ft_strdup(res);
		free(res);
	}
}

void	init_map3(t_map *map)
{
	char	*res;
	char	*line;

	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		if (*line == '\n')
		{
			free(line);
			continue ;
		}
		res = ft_strtrim(line, " \t\n");
		free(line);
		if (ft_strncmp(res, "F", 1) == 0)
			map->f = ft_strdup(res);
		else if (ft_strncmp(res, "C", 1) == 0)
			map->c = ft_strdup(res);
		free(res);
	}
}
