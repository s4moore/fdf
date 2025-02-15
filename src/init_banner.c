/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_banner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:13:06 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 18:54:54 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

void	rotate_banner(t_box *box)
{
	double	sin_theta;
	double	cos_theta;
	int		i;
	double	x;
	double	z;

	sin_theta = sin(0.01);
	cos_theta = cos(0.01);
	i = 0;
	while (i < box->banner_points)
	{
		x = box->banner[i].x;
		z = box->banner[i].z;
		box->banner[i].x = cos_theta * x + sin_theta * z;
		box->banner[i].z = -sin_theta * x + cos_theta * z;
		i++;
	}
}

void	make_banner(t_box *box)
{
	double	angle;
	double	o_x;
	double	o_z;
	int		j;

	j = 0;
	while (j < box->banner_points)
	{
		o_x = box->banner[j].x;
		o_z = box->banner[j].z;
		angle = atan2(o_z, o_x);
		box->banner[j].x = 500 * cos(angle);
		box->banner[j].z = 500 * sin(angle);
		j++;
	}
}

void	print_42(t_box *box)
{
	t_point	tmp;
	int		i;
	int		offset;

	i = 0;
	while (i < box->banner_points)
	{
		tmp = box->banner[i];
		tmp.y += box->center_y;
		tmp.x += box->center_x;
		offset = (box->line_len * tmp.y) + (box->bpp_offset * tmp.x);
		if (offset > HIGH * box->line_len * box->bpp_offset || offset < 0)
		{
			i++;
			continue ;
		}
		tmp.x -= box->center_x;
		tmp.y -= box->center_y;
		if (tmp.z > 0)
			my_pixel_put(box, tmp.x, tmp.y, encode_rgb(255, 255, 255));
		else if (*((unsigned int *)(offset + box->img_ptr)) == 0)
			my_pixel_put(box, tmp.x, tmp.y, encode_rgb(100, 100, 100));
		i++;
	}
}

int	get_points(t_box *box, int file, int y)
{
	static int	points;
	char		buf[2];
	int			b;
	int			x;

	x = 0;
	b = 1;
	while (x < 510 && b > 0)
	{
		b = read(file, buf, 2);
		if (buf[0] == '"')
			break ;
		if (buf[0] == 'U')
		{
			box->banner[points].x = x - 255;
			box->banner[points].y = y - 510;
			box->banner[points++].z = 255;
		}
		x++;
	}
	return (points);
}

void	read_42(t_box *box)
{
	char	buf[2];
	int		file;
	int		y;

	file = open("./maps/42.banner", O_RDONLY);
	box->banner = malloc(sizeof(t_point) * 126848);
	y = 0;
	while (y < 1020 && (read(file, buf, 1)))
		box->banner_points = get_points(box, file, y++);
	close(file);
}
