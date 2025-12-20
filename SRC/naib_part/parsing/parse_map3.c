/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:12:43 by nmagamad          #+#    #+#             */
/*   Updated: 2025/12/17 13:41:39 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_color_f2(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ',')
			return (1);
		if ((str[i] == ',' && i == 0)
			|| (str[i] == ',' && !ft_isdigit(str[i - 1]))
			|| (str[i] == ',' && !ft_isdigit(str[i + 1])))
			return (1);
		if (str[i] == ',')
			count++;
	}
	if (count != 2)
		return (1);
	return (0);
}

int	parse_color_f3(char **tab)
{
	int	rgb[3];

	rgb[0] = ft_atoi(tab[0]);
	rgb[1] = ft_atoi(tab[1]);
	rgb[2] = ft_atoi(tab[2]);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255
		|| rgb[2] < 0 || rgb[2] > 255)
		return (1);
	return (0);
}

int	parse_color_f(t_map *map)
{
	char	*tmp;
	char	**tmp2;

	tmp2 = NULL;
	tmp = ft_strtrim(map->f + 2, " \t");
	if (parse_color_f2(tmp))
	{
		free(tmp);
		return (printf ("Error\nColors syntaxe(c1)\n"));
	}
	tmp2 = ft_split(tmp, ',');
	free(tmp);
	if (!tmp2)
		return (printf ("Error\ncolors syntaxe(c5)\n"));
	if (parse_color_f3(tmp2))
	{
		free_tab(tmp2);
		return (printf("Error\ncolors syntaxe(c6)\n"));
	}
	free_tab(tmp2);
	return (0);
}

int	parse_map_name(char *name)
{
	int	i;

	i = 0;
	while (name[i] && name[i] != '.')
		i++;
	if (!name[i])
		return (1);
	if (name[i] != '.' || name[i + 1] != 'c'
		|| name[i + 2] != 'u' || name[i + 3] != 'b')
		return (1);
	return (0);
}
