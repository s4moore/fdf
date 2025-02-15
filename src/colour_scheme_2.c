/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_scheme_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:29:20 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 17:45:08 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

int	*rainbow_colours(void)
{
	int	*colours;

	colours = malloc(sizeof(int) * 6);
	colours[0] = encode_rgb(255, 0, 0);
	colours[1] = encode_rgb(255, 165, 0);
	colours[2] = encode_rgb(0, 255, 0);
	colours[3] = encode_rgb(0, 255, 255);
	colours[4] = encode_rgb(0, 0, 255);
	colours[5] = encode_rgb(75, 0, 130);
	return (colours);
}

void	make_it_randy(t_box *box)
{
	int	i;
	int	j;
	int	rgb[3];
	int	pos;

	i = 0;
	while (i < box->map[box->m][0].rows)
	{
		j = 0;
		while (j < box->map[box->m][0].cols)
		{
			rgb[0] = rand() % 250;
			rgb[1] = rand() % 250;
			rgb[2] = rand() % 250;
			pos = i * box->map[box->m][0].cols + j;
			if (i * box->map[box->m][0].cols + j >= box->map[box->m][0].num_pts)
				break ;
			box->colour_map[5][pos] = encode_rgb(rgb[0], rgb[1], rgb[2]);
			j++;
		}
		i++;
	}
}

void	change_colour_scheme(t_box *box)
{
	box->colour_scheme++;
	if (box->colour_scheme == box->num_colour_schemes)
		box->colour_scheme = 0;
}

void	make_it_checkered(t_box *box)
{
	int	i;
	int	j;
	int	colours[2];
	int	pos;

	colours[0] = encode_rgb(0, 0, 255);
	colours[1] = encode_rgb(255, 255, 0);
	i = 0;
	while (i < box->map[box->m][0].rows)
	{
		j = 0;
		while (j < box->map[box->m][0].cols)
		{
			pos = i * box->map[box->m][0].cols + j;
			if (i * box->map[box->m][0].cols + j >= box->map[box->m][0].num_pts)
				break ;
			box->colour_map[2][pos] = colours[((j / 10) + (i / 10)) % 2];
			j++;
		}
		i++;
	}
}

int	make_it_rainbow(t_box *box)
{
	int	i;
	int	j;
	int	*colours;
	int	pos;

	i = 0;
	colours = rainbow_colours ();
	while (i < box->map[box->m][0].rows)
	{
		j = 0;
		while (j < box->map[box->m][0].cols)
		{
			pos = i * box->map[box->m][0].cols + j;
			if (i * box->map[box->m][0].cols + j >= box->map[box->m][0].num_pts)
				break ;
			box->colour_map[1][pos] = colours[((j + i) / 9) % 6];
			j++;
		}
		i++;
	}
	free (colours);
	make_it_checkered(box);
	return (0);
}
