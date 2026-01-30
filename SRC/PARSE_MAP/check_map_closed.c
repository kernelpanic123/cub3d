/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:55:05 by abtouait          #+#    #+#             */
/*   Updated: 2026/01/30 10:17:17 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	check_char_map(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] != ' ' &&
				data->map[i][j] != '1' &&
				data->map[i][j] != '0' &&
				data->map[i][j] != 'N' &&
				data->map[i][j] != 'E' && data->map[i][j] != 'S' &&
				data->map[i][j] != 'W' && data->map[i][j] != '\n')
				{
					printf("ERROR CHAR\n");
					return (FALSE);
				}
			j++;
		}
		j = 0;
		i++;
	}
	return (TRUE);
}

int	parse_player(t_game *data)
{
	int		i;
	int		j;
	int		nbr_of_player;

	i = 0;
	j = 0;
	nbr_of_player = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'W' ||
				data->map[i][j] == 'S' || data->map[i][j] == 'E')
				nbr_of_player = nbr_of_player + 1;
			j++;
		}
		i++;
		j = 0;
	}
	return (nbr_of_player);
}

int	closed_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] != '1')
		return (FALSE);
	i = ft_strlen(line) - 2;
	if (line[i] != '1')
		return (FALSE);
	return (TRUE);
}

int	check_full_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != ' ' && line[i] != '\n')
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	check_closed_map(t_game *data)
{
	int	i;
	int	len;

	i = 0;
	len = strlen_array(data->map);
	if (check_full_line(data->map[i]) != TRUE)
		return (FALSE);
	i++;
	while (i < len - 1)
	{
		if (closed_line(data->map[i]) != TRUE)
			return (FALSE);
		i++;
	}
	if (check_full_line(data->map[len - 1]) != TRUE)
		return (FALSE);
	return (TRUE);
}
