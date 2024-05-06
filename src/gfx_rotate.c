/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:50:37 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 17:37:58 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

void	rotate_x(t_box *box, double theta)
{
	double	y;
	double	z;
	double	angle;
	int		i;

	angle = theta * box->pi_div_180;
	i = 0;
	while (i < box->map[box->m][0].num_pts)
	{
		y = box->map[box->m][box->p].points[i].y;
		z = box->map[box->m][box->p].points[i].z;
		box->map[box->m][box->p].points[i].y = y * cos(angle) - sin(angle) * z;
		box->map[box->m][box->p].points[i].z = y * sin(angle) + z * cos(angle);
		i++;
	}
}

void	rotate_y(t_box *box, double angle)
{
	double	sin_theta;
	double	cos_theta;
	double	x;
	double	z;
	int		i;

	i = 0;
	sin_theta = sin(angle * box->pi_div_180);
	cos_theta = cos(angle * box->pi_div_180);
	while (i < box->map[box->m][0].num_pts)
	{
		x = box->map[box->m][box->p].points[i].x;
		z = box->map[box->m][box->p].points[i].z;
		box->map[box->m][box->p].points[i].x = cos_theta * x + sin_theta * z;
		box->map[box->m][box->p].points[i].z = -sin_theta * x + cos_theta * z;
		i++;
	}
}
