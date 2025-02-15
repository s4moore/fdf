/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points_and_sphere.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:53:27 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 17:42:15 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

void	store_x_y_values(t_box *box)
{
	int	i;
	int	j;
	int	v[2];
	int	cols;
	int	rows;

	i = 0;
	v[0] = box->map[box->m][0].zoom;
	v[1] = box->map[box->m][1].zoom;
	cols = box->map[box->m][0].cols;
	rows = box->map[box->m][0].rows;
	while (i < box->map[box->m][0].rows)
	{
		j = 0;
		while (j < cols)
		{
			box->map[box->m][1].points[i * cols + j].x = (j - cols / 2) * v[1];
			box->map[box->m][1].points[i * cols + j].y = (i - rows / 2) * v[1];
			box->map[box->m][0].points[i * cols + j].x = (j - cols / 2) * v[0];
			box->map[box->m][0].points[i * cols + j].y = (i - rows / 2) * v[0];
			j++;
		}
		i++;
	}
}

void	fill_vals(t_box *box, char **nums, int j, int i)
{
	double	el_adj[2];
	int		pos;
	int		colour;
	int		tmp;
	int		col;

	el_adj[0] = box->map[box->m][0].elevation_adjust;
	el_adj[1] = box->map[box->m][1].elevation_adjust;
	pos = i * box->map[box->m][0].cols + j;
	box->map[box->m][1].points[pos].colour = colour;
	tmp = ft_atoi(nums[j]);
	box->map[box->m][0].points[pos].z = (double)tmp * el_adj[0];
	box->map[box->m][1].points[pos].z = (double)tmp * el_adj[1];
	if (has_colour(nums[j]))
		box->map[box->m][0].points[pos].colour = get_colour(nums[j]);
	else
	{
		colour = (int)box->map[box->m][0].points[pos].z;
		col = encode_rgb(255 - 10 * colour, colour, colour);
		box->map[box->m][0].points[pos].colour = col;
	}
	colour = box->map[box->m][0].points[pos].colour;
	free (nums[j++]);
}

void	store_z_values(t_box *box, char **nums, int i)
{
	static int	points_index;
	int			j;
	int			tmp;
	int			pos;

	if (box->reset_points_index)
	{
		points_index = 0;
		box->reset_points_index = 0;
	}
	j = 0;
	while (nums[j])
	{
		fill_vals(box, nums, j, i);
		pos = i * box->map[box->m][0].cols + j++;
		box->map[box->m][0].points[pos].index = points_index;
		box->map[box->m][1].points[pos].index = points_index++;
	}
	box->map[box->m][0].num_pts = points_index;
	box->map[box->m][1].num_pts = points_index;
	free (nums);
	nums = NULL;
}

void	make_sphere(t_box *box, double radius)
{
	double	a[2];
	int		i;
	int		j;
	double	rad;
	int		pos;

	i = 0;
	while (i < box->map[box->m][0].rows)
	{
		j = 0;
		while (j < box->map[box->m][0].cols)
		{
			pos = i * box->map[box->m][0].cols + j;
			rad = box->map[box->m][1].elevation_adjust;
			rad *= box->map[box->m][1].points[pos].z;
			rad += radius;
			a[0] = 2.0 * M_PI * j / (box->map[box->m][0].cols - 1);
			a[1] = M_PI * i / (box->map[box->m][0].rows - 1);
			box->map[box->m][1].points[pos].x = rad * sin(a[1]) * cos(a[0]);
			box->map[box->m][1].points[pos].y = rad * sin(a[1]) * sin(a[0]);
			box->map[box->m][1].points[pos].z = rad * cos(a[1]);
			j++;
		}
		i++;
	}
}
