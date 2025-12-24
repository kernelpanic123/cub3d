/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:23:36 by abtouait          #+#    #+#             */
/*   Updated: 2025/12/24 16:47:45 by abtouait         ###   ########.fr       */
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

int	rgb_to_int(char *rgb)
{
	char	**rgb_values;
	char	*tmp;
	int		result;

	tmp = NULL;
	rgb_values = ft_split(rgb, ',');
	tmp = ft_strtrim(rgb_values[0] + 2, " \t\n");
	if (!rgb_values)
		return (-1);
	result = ft_atoi(tmp) << 16
		| ft_atoi(rgb_values[1]) << 8
		| ft_atoi(rgb_values[2]);
	free_array_simple(rgb_values);
	free(tmp);
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
		while ((array[i][j] && array[i][j] == ' ') || ft_isdigit(array[i][j]))
			j++;
		if (array[i][j] == '\0' || ft_isdigit(array[i][j]))
			return (free_array(array, FALSE));
		if (ft_atoi(&array[i][j]) < 0 || ft_atoi(&array[i][j]) > 255)
			return (free_array(array, FALSE));
		i++;
		j = 0;
	}
	return (free_array(array, TRUE));
}
int valid_rgb_ceiling(t_game *data)
{
	int i;
	int j;
	char **array;

	i = 0;
	j = 0;
	array = ft_split(data->ceiling, ',');
	if (strlen_array(array) != 3)
		return (FALSE);
	while (array[i] != NULL)
	{
		while ((array[i][j] && array[i][j] == ' ') || ft_isdigit(array[i][j]))
			j++;
		if (array[i][j] == '\0' || ft_isdigit(array[i][j]))
			return (free_array(array, FALSE));
		if (ft_atoi(&array[i][j]) < 0 || ft_atoi(&array[i][j]) > 255)
			return (free_array(array, FALSE));
		i++;
		j = 0;
	}
	return (free_array(array, TRUE));
}


// int main(int argc, char **argv)
// {
// 	t_game	data;
// 	char **test;
// 	int i;

// 	i = 0;
// 	(void) argc;
// 	init_var_struct(&data, argv);
// 	get_floor(&data);
// 	printf("%d\n", valid_rgb_floor(&data));
// }
