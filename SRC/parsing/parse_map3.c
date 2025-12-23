/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:12:43 by nmagamad          #+#    #+#             */
/*   Updated: 2025/12/22 09:35:29 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

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
