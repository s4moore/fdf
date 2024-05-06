/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:42:01 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 18:30:29 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

void	main_checks(t_box *box)
{
	int	m;

	m = box->m;
	if (kill(0))
		end_program (box);
	check_mouse(box);
	check_momentum(box);
	if (box->p == 1)
		if (m == 7 || m == 8 || m == 12 || m == 13)
			box->hide = 1;
	if (box->p == 0)
		box->hide = 0;
	if (zoom(0))
		re_size(box);
}

void	main_rotation(t_box *box)
{
	rotate_x(box, -box->y_angle);
	rotate_y(box, box->x_angle);
	box->x_angle = 0;
	box->y_angle = 0;
	rotate_banner(box);
}

int	main_loop(t_box *box)
{
	int	*ll;
	int	*bpp;

	ll = &box->line_len;
	bpp = &box->bpp;
	main_checks(box);
	if (box->img)
		mlx_destroy_image(box->mlx, box->img);
	box->img = mlx_new_image(box->mlx, WIDE, HIGH);
	box->img_ptr = mlx_get_data_addr(box->img, bpp, ll, &box->e);
	draw_map(box);
	if (box->colour_scheme == 4)
		fade_colours(box);
	else if (box->colour_scheme == 5)
		make_it_randy(box);
	if (box->banner_show)
		print_42(box);
	mlx_put_image_to_window(box->mlx, box->win, box->img, 0, 0);
	main_rotation(box);
	if (box->pong)
		pong(box);
	return (1);
}
