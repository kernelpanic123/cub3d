/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:32:37 by abtouait          #+#    #+#             */
/*   Updated: 2025/12/26 17:54:11 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	init_var_struct(t_game *data)
{
	data->f_color = 0;
	data->c_color = 0;
	data->max_len = 0;
	get_floor(data);
	get_ceiling(data);
	get_north(data);
	get_west(data);
	get_south(data);
	get_east(data);
	get_max_len(data);
	equalize_map(data);
	replace_space(data);
}
