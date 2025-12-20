/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:13:12 by nmagamad          #+#    #+#             */
/*   Updated: 2025/12/17 13:29:09 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include "libft.h"
# include <fcntl.h>
# include <errno.h>
# include <stdarg.h>
# include <stdbool.h>
# include <sys/types.h>

typedef struct s_map
{
	char	*map_name;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
	int		fd;
}	t_map;

int	init_map(t_map *map, char *name);
int		parsing(char *name, t_map *map);
void	printtab(char *tableau[]);
int		map_count_line(char *file);
void	free_all(t_map *map);
int		ft_tablen(char **tab);
void	free_tab(char **array);
void	init_map2(t_map *map);
void	init_map3(t_map *map);
int		parse_color_c(t_map *map);
int		parse_walls(t_map *map, int y_len);
int		parse_walls2(t_map *map);
int		parse_color_f(t_map *map);
int		parse_map_name(char *name);

#endif