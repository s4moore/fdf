/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:40:13 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 18:33:25 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

int	mouse(int action)
{
	static int	state = 0;

	if (action == 1)
		state = 1;
	if (action == 2)
		state = 2;
	if (action == 0)
		return (state);
	if (action == -1)
		state = 0;
	return (0);
}

int	end_mouse_1(int button)
{
	if (button == 1)
		mouse(2);
	return (0);
}

int	start_mouse_1(void)
{
	mouse(1);
	return (0);
}

int	mouse_hook(int button)
{
	if (button == 1)
		start_mouse_1();
	if (button == 4)
		zoom(1);
	if (button == 5)
		zoom(2);
	return (0);
}

void	check_mouse(t_box *box)
{
	static int	start_x;
	static int	start_y;
	static int	end_x;
	static int	end_y;

	if (mouse(0) == 1)
	{
		mlx_mouse_get_pos(box->mlx, box->win, &start_x, &start_y);
		mouse(-1);
	}
	else if (mouse(0) == 2)
	{
		mlx_mouse_get_pos(box->mlx, box->win, &end_x, &end_y);
		mouse(-1);
		add_momentum(box, end_x - start_x, end_y - start_y);
		start_x = 0;
		start_y = 0;
		end_x = 0;
		end_y = 0;
	}
}
