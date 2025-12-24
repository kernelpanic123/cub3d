/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:23:03 by abtouait          #+#    #+#             */
/*   Updated: 2025/12/24 06:49:37 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int parse_rgb(t_game *data)
{
	if (!data->ceiling || !data->floor)
	{
		printf("Error\nmissing ceiling or floor color configuration\n");
		return (FALSE);
	}
	if (valid_rgb_ceiling(data) == 0 && valid_rgb_floor(data) == 0)
	{
		data->f_color = rgb_to_int(data->floor);
		data->c_color = rgb_to_int(data->ceiling);
		return (TRUE);
	}
	else
		return (FALSE);
}

int medium_parse(t_game *data, int argc, char **argv)
{
	if (smol_parse(argc, argv) == FALSE)
	{
		printf("ERROR FILE\n");
		return (FALSE);
	}
	if (check_char_map(data) == FALSE)
	{
		printf("ERROR WRONG CHAR MAP\n");
		return (FALSE);
	}
	if (check_closed_map(data) == FALSE)
	{
		printf("ERROR MAP NOT CLOSED\n");
		return (FALSE);
	}
	if (parse_player(data) != 1)
	{
		printf("ERROR NO OR MORE THAN 1 PLAYER DETECTED\n");
		return (FALSE);
	}
	return (TRUE);
}

