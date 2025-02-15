/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:28:30 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 18:18:17 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

int		WIDE;
int		HIGH;

void	start_page(t_box *box)
{
	int	i;
	int	j;

	i = 0;
	box->img_42 = mlx_xpm_file_to_image(box->mlx, "./maps/42.xpm", &i, &j);
	box->w_42 = i;
	box->h_42 = j;
	i = WIDE / 2 - 255;
	j = HIGH / 2 - 255;
	mlx_put_image_to_window(box->mlx, box->win, box->img_42, i, j);
}

void	init_box(t_box *box, char *file)
{
	box->start_map = 0;
	box->x_angle = 0;
	box->y_angle = 0;
	box->num_maps = 14;
	box->x_momentum = 0;
	box->y_momentum = 0;
	box->pi_div_180 = M_PI / 180;
	box->center_x = WIDE / 2;
	box->center_y = HIGH / 2;
	box->banner_show = 0;
	box->hide = 0;
	box->resize = 0;
	box->num_colour_schemes = 6;
	make_map_names(box);
	if (file)
	{
		if (set_map_number(box, file))
			add_map(box, file);
		check_maps(box, file);
	}
	make_maps(box, file);
	box->p = 0;
	box->m = box->start_map;
	free_colours(box);
	make_colour_maps(box);
}

void	start_program(t_box *box, char *file)
{
	init_mlx(box);
	start_page(box);
	init_box(box, file);
	rotate_x(box, 23);
	rotate_y(box, 45);
	mlx_key_hook(box->win, get_keysym, box);
	mlx_hook(box->win, 17, 1L << 17, x_pressed, box);
	mlx_hook(box->win, 5, 1L << 3, end_mouse_1, box);
	mlx_mouse_hook(box->win, mouse_hook, box);
	mlx_loop_hook(box->mlx, main_loop, box);
	mlx_loop(box->mlx);
}

void get_screen_dims()
{
    Display	*display;
    int		screen;

    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Cannot open display\n");
        return 1;
    }

    screen = DefaultScreen(display);

    WIDE = XDisplayWidth(display, screen);
	HIGH = XDisplayHeight(display, screen);

    printf("Screen width: %d, Height: %d pixels\n", WIDE, HIGH);

    XCloseDisplay(display);
    return 0;
}

int	main(int argc, char **argv)
{
	t_box	box;
	char	*file;
	int		fd;
	char	*tmp;

	get_screen_dims();
	if (argc == 2)
		file = argv[1];
	else
		file = NULL;
	if (file)
	{
		tmp = ft_strdup(argv[1]);
		fd = open(tmp, O_RDONLY);
		if (fd == -1)
		{
			free (tmp);
			perror(file);
			exit (1);
		}
		close (fd);
		free (tmp);
	}
	start_program(&box, file);
}
