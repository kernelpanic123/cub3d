/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equalize_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:28:09 by abtouait          #+#    #+#             */
/*   Updated: 2025/11/13 04:22:38 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	get_max_len(t_game *data)
{
	int	i;
	int	len;

	i = 0;
	while (data->map[i] != NULL)
	{
		len = 0;
		while (data->map[i][len] && data->map[i][len] != '\n')
			len++;
		if (len > data->max_len)
			data->max_len = len;
		i++;
	}
}

char	*fill_line(char *line, int max_len)
{
	int		i;
	int		len;
	int		has_nl;
	char	*new_line;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	has_nl = (line[len] == '\n');
	new_line = malloc(sizeof(char) * (max_len + has_nl + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_line[i] = line[i];
		i++;
	}
	while (i < max_len)
		new_line[i++] = '1';
	if (has_nl == 1)
		new_line[i++] = '\n';
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

void	equalize_map(t_game *data)
{
	int	i;
	int	len;

	i = 0;
	while (data->map[i])
	{
		len = 0;
		while (data->map[i][len])
			len++;
		if (len < data->max_len)
			data->map[i] = fill_line(data->map[i], data->max_len);
		i++;
	}
}
