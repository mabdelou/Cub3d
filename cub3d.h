/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:59:27 by mabdelou          #+#    #+#             */
/*   Updated: 2022/09/06 19:20:24 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "./CubInit/parssing.h"
# include "./libft/libft.h"

typedef struct s_map
{
	char			*content;
	struct s_map	*next;
}	t_map;

typedef struct s_img
{
	char	*addr;
	int		line_len;
	int		bpp;
	int		endien;
	int		txt_x;
	int		txt_y;
}	t_img;

typedef struct s_cub
{
	t_img	**img;
	char	player;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	char	*floor_color;
	char	*ceilling_color;
	char	**map_buffer;
	char	*buffer;
	int		*f_rgb;
	int		*c_rgb;

	void	*win;
	void	*ptr;
	void	*img_wall;
	void	*img_floor;
	void	*img_empty;
	void	*img_player;
	void	*minimap;
	int		x_pixel;
	int		y_pixel;
	int		a_map_buf;
	int		*b_map_buf;
	int		px;
	int		py;
	int		ppx;
	int		ppy;
	void	*win_cub3d;
	void	*img_black_screen;
	void	*img_of_screen;
	void	*north_wall;
	void	*south_wall;
	void	*west_wall;
	void	*east_wall;
	int		end_ray_x;
	int		end_ray_y;
	double	radien;
	double	rev_radien;
	int		ray_pixels;
	int		celing_px;
	int		wall_px;
	int		floor_px;
	double	ray_len[1500];
	int		color_of_wall[1500];
	int		wall_width[100];
	int		ray_hit_pos[1500];
	double	up_len;
	double	down_len;
	double	right_len;
	double	left_len;
}t_cub;

// utilitis functions
int		ft_strlen(char *str);
double	ft_to_radien(int degree);
void	ft_error(char *error);
char	*get_next_line(int fd);

// parssing part
void	validate_map(t_cub *cub, char *path);
void	ft_err(char *msg);
void	fill_colors(t_cub *cub, char *new);
void	fill_elemenets(t_cub *cub, char *new, char *join);
void	handle_elements(char *str, t_cub *cub);
void	check_double(t_map *head);
void	ft_lstadd_back_min(t_map **lst, t_map *new);
void	check_elements(t_map *head, t_cub *cub);
void	check_color(char *color, t_cub *cub, int is_floor);
int		calcule_map_lines(t_map *head);
void	check_is_surrounded(t_cub *cub);
int		is_valid_char(char c);
void	check_is_one_player(char c, int *players);
void	check_playes_zero(t_cub *cub, char *str, int i, int j);
void	check_map_characthers(t_cub *cub);
void	fill_the_map(t_map *head, t_cub *cub);

void	check_empty_line(t_map *head);
void	check_extension(char *map);
void	free_list(t_map *head);
void	_mlx_init(t_cub *cub);
void	check_path_of_map_file(char *path);
void	get_buff_of_map(t_cub *cub, char *path);
char	*get_texture_path(char *ptr);
void	check_north_texture_path(t_cub *cub);
void	check_south_texture_path(t_cub *cub);
void	check_west_texture_path(t_cub *cub);
void	check_east_texture_path(t_cub *cub);
void	check_map_if_valid(t_cub *cub);
void	get_len_of_map(t_cub *cub);

//execution part
void	player_pos(t_cub *cub, int a);
void	rays_firing(t_cub *cub);
void	engin(t_cub *cub, int a, int b);
void	draw_line(t_cub *cub);
int		key_press(int keycode, t_cub *cub);
int		mouse_mv(int x, int y, t_cub *cub);
int		update( t_cub *cub);
int		ft_close(t_cub *cub);

#endif
