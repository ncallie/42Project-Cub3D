/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:16:07 by ncallie           #+#    #+#             */
/*   Updated: 2022/04/08 15:07:11 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx/mlx.h"
# include "../Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>

# define RETURN_SUCCESS 0
# define RETURN_FAILURE 1

# define TEX_W 64
# define TEX_H 64
# define SCREEN_W 1280
# define SCREEN_H 720

# define MAX_FD 256
# define BUFFER_SIZE 1024

# define FLOOR 0
# define CEILING 1

enum e_key {
	KEY_ESC = 53,
	KEY_EVENT_PRESS = 2,
	KEY_EVENT_RELEASE = 3,
	KEY_EVENT_EXIT = 17,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_LEFT = 123,
	KEY_RIGHT = 124
};

enum e_dir {
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3
};

typedef struct s_node	t_node;

typedef struct s_node
{
	char		*map;
	t_node		*next;
}t_node;

typedef struct s_maplist
{
	int			size;
	t_node		*head;
	t_node		*tail;
}t_maplist;

typedef struct s_ray
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
}t_ray;

typedef struct s_img
{
	void		*img;
	char		*img_addr;
	int			*data;
	int			line_size;
	int			bpp;
	int			endian;
	int			img_width;
	int			img_height;
}t_img;

typedef struct s_info
{
	void		*mlx;
	void		*win;
	int			**buf;
	int			**texture;
	char		**map;
	int			map_width;
	int			map_height;
	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			player;
	int			color_flag;
	int			dir_flag;
	int			pos_flag;
	int			floor;
	int			ceiling;
	t_img		img;
	t_ray		ray;
	t_maplist	*list;
}t_info;

typedef struct s_calc
{
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	int			texNum;
	double		wallX;
	int			texX;
	int			texY;
	double		step;
	double		texPos;
	double		spriteX;
	double		spriteY;
}t_calc;


int			get_next_line(int fd, char **line);
char		*ft_strjoin_free(char *s1, char *s2);
void		init_info(t_info *info);
void		init_map(t_info *info);
int			key_press(int keycode, t_info *info);
int			key_release(int keycode, t_info *info);
void		player_move(t_info *info);
t_maplist	*create_list(void);
t_node		*create_node(char *line);
void		add_node(t_maplist *list, t_node *node);
void		parse(int argc, char **argv, t_info *info);
void		load_texture(t_info *info, int dir, char *path);
void		parse_map(char *line, t_info *info);
void		parse_last(t_info *info, char *line);
void		get_background_color(char *line, t_info *info, int flag);
int			get_textures(char *line, t_info *info);
void		dup_map(t_info *info);
void		get_map_info(t_info *info);
void		player_pos(t_info *info, int i, int j);
void		init_dda(t_info *info, t_calc *calc);
void		perform_dda(t_info *info, t_calc *calc);
void		start_ray(int x, t_info *info, t_calc *calc);
void		init_wall_texture(t_info *info, t_calc *calc);
void		input_wall_texture(int x, t_info *info, t_calc *calc);
void		exit_error(char *err_msg);
void		system_error(char *err_msg);
void		free_exit_error(char **str, char *err_msg);
int			free_return_error(char **str);
int			ft_splitlen(char **str);
void		free_double_char(char **str);
void		free_list(t_info *info);
void		deinitialize(t_info *info);
void		exit_error(char *err_msg);
void		system_error(char *err_msg);

#endif
