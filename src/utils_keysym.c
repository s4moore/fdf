/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_keysym.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:40:57 by samoore           #+#    #+#             */
/*   Updated: 2024/03/19 16:26:57 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

void	check_map_change(int keysym, t_box *box)
{
	if (keysym == MINUS)
	{
		box->m--;
		if (box->m == -1)
			box->m = box->num_maps - 1;
		free_colours(box);
		make_colour_maps(box);
		box->hide = 0;
	}
	if (keysym == PLUS)
	{
		box->m++;
		if (box->m == box->num_maps)
			box->m = 0;
		free_colours(box);
		make_colour_maps(box);
		box->reset = 0;
	}
}

void	more_keysym(int keysym, t_box *box)
{
	if (keysym == P)
		box->pong = !box->pong;
	if (keysym == C)
		change_colour_scheme(box);
	if (keysym == G)
	{
		box->p = !box->p;
		box->hide = 0;
	}
	check_map_change(keysym, box);
}

int	get_keysym(int keysym, t_box *box)
{
	if (keysym == XK_Escape)
		kill (1);
	if (keysym == RIGHT)
		box->center_x += 10;
	if (keysym == B)
	{
		box->banner_show = !box->banner_show;
	}
	if (keysym == LEFT)
		box->center_x -= 10;
	if (keysym == UP)
		box->center_y -= 7;
	if (keysym == DOWN)
		box->center_y += 7;
	if (keysym == H)
		box->hide = !box->hide;
	more_keysym(keysym, box);
	return (0);
}
