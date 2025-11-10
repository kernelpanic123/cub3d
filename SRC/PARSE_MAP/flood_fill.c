/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:53:23 by abtouait          #+#    #+#             */
/*   Updated: 2025/11/10 21:33:16 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	find_x_player(t_game *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E' || data->map[i][j] == 'S' || data->map[i][j] == 'W')
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

int	find_y_player(t_game *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E' || data->map[i][j] == 'S' || data->map[i][j] == 'W')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}
void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
}
void flood_map(t_game *data)
{
	int y_player;
	int x_player;
	
	y_player = find_y_player(data);
	x_player = find_x_player(data);
	flood_fill(data->map, y_player, x_player);
}
int main(int argc, char **argv)
{
	t_game	data;
	(void) argc;
	init_var_struct(&data, argv);
	get_map(&data);
	flood_map(&data);
	int i = 0;
	while (data.map[i] != NULL)
	{
		printf("%s\n", data.map[i]);
		i++;
	}
	
}