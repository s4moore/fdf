/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_momentum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:33:57 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 18:34:46 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

void	add_momentum(t_box *box, int x, int y)
{
	box->x_momentum += x;
	box->y_momentum += y;
}

void	check_y_momentum(t_box *box)
{
	if (box->y_momentum != 0)
	{
		box->y_angle += box->y_momentum / 80;
		box->y_momentum -= box->y_momentum / 80;
		if (box->y_momentum > 0)
		{
			box->y_momentum--;
			box->y_angle++;
		}
		else
		{
			box->y_momentum++;
			box->y_angle--;
		}
	}
}

void	check_x_momentum(t_box *box)
{
	if (box->x_momentum != 0)
	{
		box->x_angle += box->x_momentum / 80;
		box->x_momentum -= box->x_momentum / 80;
		if (box->x_momentum > 0)
		{
			box->x_momentum--;
			box->x_angle++;
		}
		else
		{
			box->x_momentum++;
			box->x_angle--;
		}
	}
}

void	check_momentum(t_box *box)
{
	check_y_momentum(box);
	check_x_momentum(box);
}
