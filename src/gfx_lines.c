/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:36:57 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 18:04:39 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

void	prep_line(t_box *box, t_point *start, t_point *end)
{
	box->line.dx = abs((int)end->x - (int)start->x);
	box->line.dy = -abs((int)end->y - (int)start->y);
	if (start->x < end->x)
		box->line.sx = 1;
	else
		box->line.sx = -1;
	if (start->y < end->y)
		box->line.sy = 1;
	else
		box->line.sy = -1;
	box->line.err = box->line.dx + box->line.dy;
}

int	my_pixel_put(t_box *box, int x, int y, int colour)
{
	int	offset;

	x = x + box->center_x;
	y = y + box->center_y;
	offset = (box->line_len * y) + (x * box->bpp_offset);
	if (x >= 0 && x < WIDE && y >= 0 && y < HIGH)
		*((unsigned int *)(offset + box->img_ptr)) = colour;
	return (0);
}

void	draw_points(t_box *box, int *x, int *y, t_point *start)
{
	int	colour;

	colour = box->colour_map[box->colour_scheme][start->index];
	my_pixel_put(box, *x, *y, colour);
	box->line.e2 = 2 * box->line.err;
	if (box->line.e2 >= box->line.dy)
	{
		box->line.err += box->line.dy;
		*x += box->line.sx;
	}
	if (box->line.e2 <= box->line.dx)
	{
		box->line.err += box->line.dx;
		*y += box->line.sy;
	}
}

void	draw_line(t_box *box, t_point *start, t_point *end)
{
	int		x;
	int		y;

	if (-start->x < box->center_x - WIDE && end->x < box->center_x - WIDE)
		return ;
	if (start->x >= WIDE - box->center_x && end->x >= WIDE - box->center_x)
		return ;
	if (-start->y < box->center_y - HIGH && end->y < box->center_y - HIGH)
		return ;
	if (start->y >= HIGH - box->center_y && end->y >= HIGH - box->center_y)
		return ;
	if (box->hide && start->z < 0)
		return ;
	prep_line(box, start, end);
	x = (int)start->x;
	y = (int)start->y;
	while (x != (int)end->x || y != (int)end->y)
		draw_points(box, &x, &y, end);
}
