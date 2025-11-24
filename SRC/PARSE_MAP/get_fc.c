/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:23:36 by abtouait          #+#    #+#             */
/*   Updated: 2025/11/22 16:10:03 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void get_floor(t_game *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->file[i] != NULL)
	{
		while (data->file[i][j] == ' ')
			j++;
		if (data->file[i][j] == 'F')
			data->floor = ft_strdup(data->file[i]);
		j = 0;
		i++;
	}
}
void get_ceiling(t_game *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->file[i] != NULL)
	{
		while (data->file[i][j] == ' ')
			j++;
		if (data->file[i][j] == 'C')
			data->ceiling = ft_strdup(data->file[i]);
		j = 0;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_game	data;
	char **test;
	int i;

	i = 0;
	(void) argc;
	init_var_struct(&data, argv);
	get_ceiling(&data);
	get_floor(&data);
	test = ft_split(data.floor, ',');
	while(test[i])
	{
		printf("%s\n", test[i]);
		i++;
	}
	
}
int	rgb_to_int(char *rgb)
{
	char	**rgb_values;
	int		result;

	rgb_values = ft_split(rgb, ',');
	if (!rgb_values)
		return (-1);
	result = ft_atoi(rgb_values[0]) << 16
		| ft_atoi(rgb_values[1]) << 8
		| ft_atoi(rgb_values[2]);
	free_all(rgb_values);
	return (result);
}

int valid_rgb_floor(t_game *data)
{
	int i;
	int j;
	char **array;
	
	i = 0;
	j = 0;
	array = ft_split(data->floor, ',');
	if (strlen_array(array) != 3)
		return (FALSE);
	while (array[i] != NULL)
	{
		while (array[i][j] && array[i][j] == ' ')
			j++;
		if (array[i][j] == '\0' || !ft_isdigit(array[i][j]))
			free_array(array, FALSE);
		if (ft_atoi(&array[i][j]) < 0 || ft_atoi(&array[i][j]) > 255)
			free_array(array, FALSE);
		i++;
		j = 0;
	}
	return (free_array(array, TRUE));
}
