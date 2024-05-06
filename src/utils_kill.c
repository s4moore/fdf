/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_kill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:43:44 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 18:43:20 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

void	clear_maps(t_box *box)
{
	t_prjct	*tmp;
	t_edge	*tmp2;
	int		i;

	i = 0;
	while (i < box->num_maps)
	{
		free (box->map[i][0].points);
		free (box->map[i][0].edges);
		free (box->map[i][1].points);
		free (box->map[i][1].edges);
		free (box->map[i]);
		i++;
	}
	free (box->map);
}

void	free_colours(t_box *box)
{
	int	i;

	i = 0;
	while (i < box->num_colour_schemes)
		free (box->colour_map[i++]);
	free (box->colour_map);
}

void	end_program(t_box *box)
{
	int	i;

	i = 0;
	while (i < box->num_maps)
		free (box->map_names[i++]);
	free (box->map_names);
	clear_maps(box);
	free_colours(box);
	free (box->banner);
	mlx_destroy_image(box->mlx, box->img);
	mlx_destroy_image(box->mlx, box->img_42);
	mlx_destroy_window(box->mlx, box->win);
	mlx_destroy_display(box->mlx);
	free (box->mlx);
	exit (1);
}

int	kill(int input)
{
	static int	kill = 0;

	if (input == 1)
		kill = 1;
	return (kill);
}

int	x_pressed(void)
{
	kill (1);
	return (0);
}
