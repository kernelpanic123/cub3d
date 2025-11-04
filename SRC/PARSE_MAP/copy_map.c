/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:29:11 by abtouait          #+#    #+#             */
/*   Updated: 2025/11/04 22:06:04 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file ,O_RDONLY);
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
	fd = open(file , O_RDONLY);
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
int count_line_map(t_game *data)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (data->file[i] != NULL)
	{
		if (char_map(data->file[i]) == TRUE)
		{
			while (data->file[i] != NULL)
			{
				i++;
				len++;
			}
			return (len);
		}
		i++;
	}
	return (len);
}

int	char_map(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'E' && line[i] != 'S' && line[i] != ' ' && line[i] != '\n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
void get_map(t_game *data)
{
	int i;
	int len;
	int j;

	i = 0;
	j = 0;
	len = count_line_map(data);
	data->map = malloc(sizeof(char *) * (len + 1));
	while (data->file[i] != NULL)
	{
		if (char_map(data->file[i]) == TRUE)
		{
			while (data->file[i] != NULL)
			{
				data->map[j] = ft_strdup(data->file[i]);
				i++;
				j++;
			}
			data->map[j] = NULL;
			return ;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	t_game	data;
	(void)argc;
	
	init_var_struct(&data, argv);
	get_map(&data);
	int i = 0;
	while (data.map[i] != NULL)
	{
		printf("%s", data.map[i]);
		i++;
	}
}