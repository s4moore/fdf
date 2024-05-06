/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:00:33 by samoore           #+#    #+#             */
/*   Updated: 2024/03/12 14:00:41 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

int	encode_rgb(t_byte red, t_byte green, t_byte blue)
{
	return (red << 16 | green << 8 | blue);
}

double	zoom(int trigger)
{
	static double	value = 0;
	static int		resize = 0;

	if (trigger == 1)
	{
		resize = 1;
		value = 1;
	}
	if (trigger == 2)
	{
		resize = 1;
		value = -1;
	}
	if (trigger == 0)
		return (resize);
	if (trigger == -1)
	{
		resize = 0;
		return (value);
	}
	return (0);
}
