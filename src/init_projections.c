/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_projections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:51:32 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 18:22:59 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

void	set_values(t_prjct *project, double z, double z_sz, double e_ad)
{
	project->zoom = z;
	project->zoom_size = z_sz;
	project->elevation_adjust = e_ad;
}

void	prepare_maps_2(t_box *box)
{
	set_values(&box->map[9][0], 25, 2, 17);
	set_values(&box->map[9][1], 400, 10, 4);
	set_values(&box->map[10][0], 25, 5, 15);
	set_values(&box->map[10][1], 400, 10, 2);
	set_values(&box->map[11][0], 25, 5, 15);
	set_values(&box->map[11][1], 400, 10, 4);
	set_values(&box->map[12][0], 5, 3, 1);
	set_values(&box->map[12][1], 400, 10, .52);
	set_values(&box->map[13][0], 12, 3, 1);
	set_values(&box->map[13][1], 400, 10, 0.9);
	if (box->num_maps == 15)
	{
		set_values(&box->map[14][0], 70, 5, 15);
		set_values(&box->map[14][1], 400, 10, 2.5);
	}
}

void	prepare_maps(t_box *box)
{
	set_values(&box->map[0][0], 50, 8, 5);
	set_values(&box->map[0][1], 400, 10, 2.5);
	set_values(&box->map[1][0], 20, 5, 15);
	set_values(&box->map[1][1], 400, 15, 2.5);
	set_values(&box->map[2][0], 15, 5, 15);
	set_values(&box->map[2][1], 400, 10, 1.5);
	set_values(&box->map[3][0], 70, 5, 45);
	set_values(&box->map[3][1], 450, 10, 2);
	set_values(&box->map[4][0], 70, 5, 15);
	set_values(&box->map[4][1], 350, 15, 2.5);
	set_values(&box->map[5][0], 50, 5, 3);
	set_values(&box->map[5][1], 350, 15, 1);
	set_values(&box->map[6][0], 70, 5, 15);
	set_values(&box->map[6][1], 350, 15, 2.5);
	set_values(&box->map[7][0], 2.5, 0.5, .1);
	set_values(&box->map[7][1], 350, 10, .3);
	set_values(&box->map[8][0], 7, 0.5, 5);
	set_values(&box->map[8][1], 400, 10, 1.5);
	prepare_maps_2(box);
}
