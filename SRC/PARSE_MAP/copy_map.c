/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:29:11 by abtouait          #+#    #+#             */
/*   Updated: 2025/11/01 02:05:55 by abtouait         ###   ########.fr       */
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
int main(int argc, char **argv)
{
	t_game	data;
	(void)argc;
	
	init_var_struct(&data, argv);
	get_north(&data);
	get_east(&data);
	get_south(&data);
	get_west(&data);
	printf("%s", data.north);
	printf("%s", data.south);
	printf("%s", data.west);
	printf("%s", data.east);
	
}