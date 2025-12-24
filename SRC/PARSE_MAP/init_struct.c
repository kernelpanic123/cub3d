/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:32:37 by abtouait          #+#    #+#             */
/*   Updated: 2025/12/24 06:58:27 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	init_var_struct(t_game *data, char **argv)
{
	ft_memset(data, 0, sizeof(t_game));
	data->file = parse_map(argv[1]);
	data->f_color = 0;
	data->c_color = 0;
	data->max_len = 0;
	get_map(data);
	get_floor(data);
	get_ceiling(data);
	get_north(data);
	get_west(data);
	get_south(data);
	get_east(data);
	replace_space(data);
	get_max_len(data);
	equalize_map(data);
	
}