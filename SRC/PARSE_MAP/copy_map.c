/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:29:11 by abtouait          #+#    #+#             */
/*   Updated: 2025/12/26 11:43:27 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	count = 0;
	if (fd < 0)
		return (FALSE);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**parse_map(char *file)
{
	int		fd;
	char	*line;
	char	**arrays;
	int		i;
	int		total_lines;

	i = 0;
	total_lines = count_lines(file);
	arrays = malloc(sizeof(char *) * (total_lines + 1));
	if (!arrays)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		arrays[i] = line;
		i++;
		line = get_next_line(fd);
	}
	arrays[i] = NULL;
	close(fd);
	return (arrays);
}

int	search_map_start(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file[i] != NULL)
	{
		j = 0;
		while (data->file[i][j] == ' ')
			j++;
		if (data->file[i][j] == '1' || data->file[i][j] == '0')
			return (i);
		i++;
	}
	return (-1);
}

void	get_map(t_game *data)
{
	int	i;
	int	len;

	data->map = NULL;
	len = 0;
	i = search_map_start(data);
	if (i == -1)
	{
		return ;
	}
	while (data->file[i] != NULL)
	{
		len++;
		i++;
	}
	data->map = malloc(sizeof(char *) * (len + 1));
	i = search_map_start(data);
	len = 0;
	while (data->file[i] != NULL)
	{
		data->map[len] = ft_strdup(data->file[i]);
		i++;
		len++;
	}
	data->map[len] = NULL;
}
