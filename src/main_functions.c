/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:43:43 by samoore           #+#    #+#             */
/*   Updated: 2024/03/16 17:20:54 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

void	re_size(t_box *box)
{
	double	scale;
	int		i;
	double	b_zoom;

	i = 0;
	b_zoom = box->map[box->m][box->p].zoom;
	scale = ((b_zoom + zoom(-1) * box->map[box->m][box->p].zoom_size) / b_zoom);
	while (i < box->map[box->m][0].num_pts)
	{
		box->map[box->m][box->p].points[i].x *= scale;
		box->map[box->m][box->p].points[i].y *= scale;
		box->map[box->m][box->p].points[i].z *= scale;
		i++;
	}
}

void	draw_map(t_box *box)
{
	t_prjct	tmp;
	int		i;

	tmp = box->map[box->m][box->p];
	i = 0;
	while (i < box->map[box->m][box->p].num_edges)
	{
		draw_line(box, tmp.edges[i].start, tmp.edges[i].end);
		i++;
	}
}

void	pong_2(t_box *box)
{
	static int	vert;
	t_point		*points;

	points = box->map[box->m][box->p].points;
	if (vert == 1 && box->center_y <= HIGH)
	{
		rotate_y(box, 1);
		box->center_y += 5;
	}
	else
	{
		vert = 0;
		rotate_y(box, -1);
		box->center_y -= 5;
		if (box->center_y <= 0)
			vert = 1;
	}
}

void	pong(t_box *box)
{
	static int	horiz;
	t_point		*points;

	points = box->map[box->m][box->p].points;
	if (horiz == 1 && box->center_x <= WIDE)
	{
		rotate_x(box, 1);
		box->center_x += 5;
	}
	else
	{
		horiz = 0;
		rotate_x(box, -1);
		box->center_x -= 5;
		if (box->center_x <= 0)
			horiz = 1;
	}
	pong_2(box);
}
