/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:35:33 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 17:44:09 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

int	check_col(int col)
{
	static int	dir = 1;

	if (col == 0)
		return (100);
	if (col < 255 && dir == 1)
		return (++col);
	if (col == 255)
	{
		dir = -1;
		return (--col);
	}
	if (col > 99)
		return (--col);
	dir = 1;
	return (99);
}

void	fade_colours(t_box *box)
{
	static int	rgb[3];
	static int	col = 0;
	int			new_col;
	int			i;

	i = 0;
	rgb[col] = check_col(rgb[col]);
	if (rgb[col] == 99)
		col++;
	if (col == 3)
		col = 0;
	new_col = encode_rgb(rgb[0], rgb[1], rgb[2]);
	while (i < box->map[box->m][0].num_pts)
		box->colour_map[4][i++] = new_col;
}

int	has_colour(char *num)
{
	int	i;

	i = 0;
	while (num[i] != 0)
		if (num[i++] == ',')
			return (1);
	return (0);
}

int	get_colour(char	*num)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (num[i] != 'x')
		i++;
	i++;
	while (num[i] != 0)
	{
		result *= 16;
		if (num[i] >= '0' && num[i] <= '9')
			result += num[i] - '0';
		if (num[i] >= 'a' && num[i] <= 'f')
			result += num[i] - 'a' + 10;
		if (num[i] >= 'A' && num[i] <= 'F')
			result += num[i] - 'A' + 10;
		i++;
	}
	return (result);
}
