/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:33:09 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 17:35:31 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define _GNU_SOURCE
# include "mlx.h"
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

# define WIDE	1920
# define HIGH	850
# define LEFT	65361
# define RIGHT	65363	
# define UP		65362
# define DOWN	65364
# define PLUS	0xffab
# define MINUS  0xffad
# define B		0x62
# define C		0x63
# define F		0x66
# define G		0x67
# define H		0x68
# define P		0x70
# define R		0x72

typedef unsigned char	t_byte;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	err;
	int	e2;
	int	sx;
	int	sy;
}	t_line;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		colour;
	int		index;
}	t_point;

typedef struct s_banner_points
{
	struct s_banner_points	*next;
	double					x;
	double					y;
	double					z;
}	t_ban_point;

typedef struct s_edge
{
	t_point	*start;
	t_point	*end;
}	t_edge;

typedef struct s_projection
{
	t_edge	*edges;
	t_point	*points;
	int		num_pts;
	int		cols;
	int		rows;
	int		num_edges;
	double	zoom_size;
	double	zoom;
	double	elevation_adjust;
}	t_prjct;

typedef struct s_box
{
	t_prjct	**map;
	int		p;
	int		m;
	void	*mlx;
	void	*win;
	char	*nums;
	int		banner_show;
	int		bpp_offset;
	int		center_x;
	int		center_y;
	int		x_angle;
	int		y_angle;
	int		x_momentum;
	int		y_momentum;
	int		cols;
	int		rows;
	int		num_pts;
	int		hide;
	double	pi_div_180;
	int		resize;
	void	*img;
	void	*img_42;
	int		w_42;
	int		h_42;
	char	*img_ptr;
	int		bpp;
	int		e;
	int		line_len;
	int		banner_points;
	int		pong;
	int		banner_rotation_points;
	int		colour_scheme;
	int		num_colour_schemes;
	int		**colour_map;
	int		reset;
	int		reset_join_globe;
	int		reset_join_flat;
	int		reset_points_index;
	t_line	line;
	t_point	*banner;
	char	**map_names;
	int		map_num;
	int		num_maps;
	int		start_map;
}	t_box;

void	add_momentum(t_box *box, int x, int y);
void	assign_colour_mem(t_box *box);
void	change_colour_scheme(t_box *box);
void	check_free(t_box *box, char *file);
void	check_maps(t_box *box, char *file);
void	check_momentum(t_box *box);
void	check_mouse(t_box *box);
int		count_nums(char **nums, int *check);
void	draw_line(t_box *box, t_point *start, t_point *end);
void	draw_map(t_box *box);
int		encode_rgb(t_byte red, t_byte green, t_byte blue);
int		end_mouse_1(int button);
void	end_program(t_box *box);
int		ft_atoi(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split_space(char *str);
char	*ft_strdup(char *str);
void	fade_colours(t_box *box);
void	free_colours(t_box *box);
void	free_everything(t_box *box);
int		get_colour(char *num);
int		get_keysym(int keysym, t_box *box);
int		has_colour(char *num);
void	init_box(t_box *box, char *file);
void	init_mlx(t_box *box);
int		kill(int input);
void	make_banner(t_box *box);
void	make_colour_maps(t_box *box);
t_edge	*make_flat_map(t_box *box);
t_edge	*make_globe_map(t_box *box);
void	make_it_checkered(t_box *box);
void	make_it_liney(t_box *box);
int		make_it_rainbow(t_box *box);
void	make_it_randy(t_box *box);
void	make_map_names(t_box *box);
int		main_loop(t_box *box);
void	make_sphere(t_box *box, double radius);
int		mouse(int action);
int		mouse_hook(int button);
void	make_maps(t_box *box, char *file);
int		my_pixel_put(t_box *box, int x, int y, int colour);
void	pong(t_box *box);
void	prepare_maps(t_box *box);
void	print_42(t_box *box);
void	read_42(t_box *box);
void	read_map(t_box *box, char *file, int m);
void	re_size(t_box *box);
void	rotate_banner(t_box *box);
void	rotate_x(t_box *box, double theta);
void	rotate_y(t_box *box, double theta);
void	store_x_y_values(t_box *box);
void	store_z_values(t_box *box, char **nums, int i);
int		x_pressed(void);
double	zoom(int trigger);
#endif
