/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 02:10:21 by abtouait          #+#    #+#             */
/*   Updated: 2025/11/18 04:45:08 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "SRC/GNL/get_next_line.h"
# include "mlx/mlx.h"
#include "math.h"

# define TRUE 0
# define FALSE 1
# define BLOCK 50

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	
} t_texture;

typedef struct s_game
{
	char		**file;
	char		*north;
	char		*west;
	char		*south;
	char		*east;
	char		*floor;
	char		*ceiling;
	char		**map;
	int			max_len;
	void		*mlx;
	void		*mlx_win;
	t_texture	screen;
	t_texture	wall;
	t_texture	air;
	t_texture	player;
	int			screen_w;
	int			screen_h;
	
} t_game;

typedef struct s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;//(perpendiculaire au vecteur direction qui determine le FOV
	double		plany;
	int 		x;// nombres de rayon
	double		cameraX;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		deltadistx;
	double		deltadisty;
} t_ray;




//PARSE_MAP
int		check_extension(char *str);
int		open_map(char *str);
int		smol_parse(int argc, char **argv);
int		count_lines(char *file);
char	**parse_map(char *file);
void	init_var_struct(t_game *data, char **argv);
void	get_north(t_game *data);
void	get_west(t_game *data);
void	get_south(t_game *data);
void	get_east(t_game *data);
void	get_ceiling(t_game *data);
void	get_floor(t_game *data);
int		search_map_start(t_game *data);
void	get_map(t_game *data);
int		check_char_map(t_game *data);
int		parse_player(t_game *data);
int		closed_line(char *line);
int		check_full_line(char *line);
int		check_closed_map(t_game *data);
int		medium_parse(t_game *data, int argc, char **argv);
int		find_x_player(t_game *data);
int	find_y_player(t_game *data);
void	flood_fill(char **map, int y, int x);
void flood_map(t_game *data);
void replace_space(t_game *data);
char	*fill_line(char *line, int max_len);
void	equalize_map(t_game *data);
void	get_max_len(t_game *data);

//UTILS
int		strlen_array(char **array);

#endif