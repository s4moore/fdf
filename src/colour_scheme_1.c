/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_scheme_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:31:57 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 17:43:01 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

void	make_it_fadey(t_box *box)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	while (i < box->map[box->m][0].rows)
	{
		j = 0;
		while (j < box->map[box->m][0].cols)
		{
			pos = i * box->map[box->m][0].cols + j;
			if (pos >= box->map[box->m][0].num_pts)
				break ;
			box->colour_map[4][pos] = encode_rgb(0, 0, 0);
			j++;
		}
		i++;
	}
}

void	make_it_liney(t_box *box)
{
	int	i;
	int	j;
	int	colours[2];
	int	pos;

	colours[0] = encode_rgb(0, 0, 0);
	colours[1] = encode_rgb(0, 255, 100);
	i = 0;
	while (i < box->map[box->m][0].rows)
	{
		j = 0;
		while (j < box->map[box->m][0].cols)
		{
			pos = i * box->map[box->m][0].cols + j;
			if (pos >= box->map[box->m][0].num_pts)
				break ;
			box->colour_map[3][pos] = colours[(j / 10) % 2];
			j++;
		}
		i++;
	}
	make_it_rainbow(box);
}

void	make_colour_maps(t_box *box)
{
	int	i;
	int	col;
	int	num_pts;

	i = 0;
	box->colour_map = ft_calloc(sizeof(int *), box->num_colour_schemes);
	num_pts = box->map[box->m][0].num_pts;
	while (i < box->num_colour_schemes)
		box->colour_map[i++] = ft_calloc(sizeof(int), num_pts);
	i = 0;
	while (i < box->map[box->m][0].num_pts)
	{
		if (box->map[box->m][0].points[i].colour == 0)
		{
			col = (int)box->map[box->m][0].points[i].z;
			if (col < 0)
				col = 0;
			box->colour_map[0][i] = encode_rgb(255 - 10 * col, col, col);
		}
		else
			box->colour_map[0][i] = box->map[box->m][0].points[i].colour;
		i++;
	}
	make_it_liney(box);
}
