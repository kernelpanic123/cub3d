/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 02:10:21 by abtouait          #+#    #+#             */
/*   Updated: 2025/11/22 16:14:15 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "SRC/GNL/get_next_line.h"
# include "mlx/mlx.h"
# include <X11/keysym.h>
#include "math.h"

# define TRUE 0
# define FALSE 1
# define BLOCK 50

typedef struct s_ray t_ray;


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
	int			w_key;
	int			d_key;
	int			s_key;
	int			a_key;
	int			left_key;
	int			right_key;
	t_ray		*ray;
	t_texture	textures[4];
	
} t_game;

typedef struct s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;//("perpendiculaire" au vecteur direction qui determine le FOV
	double		plany;
	int 		x;// nombres de rayon
	double		cameraX;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy; 
	double		sidedistx; 
	double		sidedisty; 
	int			side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double		perpwalldist;
	int			drawstart;
	int			drawend;
	int			lineheight;
	int			texture_id;
    double		wallx;
    int			texx;
    double		step;
    double		texpos;
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
int		find_y_player(t_game *data);
void	flood_fill(char **map, int y, int x);
void	flood_map(t_game *data);
void	replace_space(t_game *data);
char	*fill_line(char *line, int max_len);
void	equalize_map(t_game *data);
void	get_max_len(t_game *data);

//UTILS
int		strlen_array(char **array);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, int start, int len);

//utils_rgb
int	ft_isdigit(int c);
int free_array(char **array, int s);
int	ft_atoi(char *str);

//handle key
int		wich_input_press(int keysim, t_game *data);
int		wich_key_release(int keysim, t_game * data);
void	move_forward(t_game *g);
int		game_loop(t_game *data);
void	move_backward(t_game *g);
void	move_right(t_game *g);
void	move_left(t_game *g);
void rotate_left(t_game *g);
void rotate_right(t_game *g);

//draw
void			my_pixel_put(t_texture *tx, int x, int y, int color);
unsigned int	get_texture_pixel(t_texture *tx, int x, int y);
void			load_texture(t_game *g, t_texture *tx, char *path);

//main
void	initialize_window(t_game *data);

//raycast
void	dda_loop(t_game *data, t_ray *r);
void	init_param2(t_ray *r);
void	init_param(t_game *data, t_ray *r);
void	calcul_dist_wall(t_game *data, t_ray *r);

//init_pos
void	get_dir_player(t_ray *r, t_game *data);
void	get_plan_cam(t_ray *r, t_game *data);
void	get_map_pos(t_ray *r);
void	init_player(t_ray *r, t_game *data);

//render
void	calcul_texture_id(t_ray *r);
void	calculate_texture_coords(t_game *data, t_ray *r);
void	draw_wall_textured(t_game *data, t_ray *r);
void	engine_3d(t_game *g, t_ray *r);
int		render(t_game *g);

#endif