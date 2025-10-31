/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 02:10:21 by abtouait          #+#    #+#             */
/*   Updated: 2025/10/31 14:29:57 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "SRC/GNL/get_next_line.h"
# include "mlx/mlx.h"

# define TRUE 0
# define FALSE 1

//PARSE_MAP
int check_extension(char *str);
int open_map(char *str);
int smol_parse(int argc, char **argv);

//UTILS

#endif