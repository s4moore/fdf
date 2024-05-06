/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:41:21 by samoore           #+#    #+#             */
/*   Updated: 2024/03/19 14:41:23 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

void	check_free(t_box *box, char *file)
{
	int	i;

	write(1, "Error reading map: ", 19);
	write(1, file, ft_strlen(file));
	write(1, "\n", 1);
	i = 0;
	while (i < box->num_maps)
		free(box->map_names[i++]);
	free (box->map_names);
	free (box->banner);
	mlx_destroy_image(box->mlx, box->img);
	mlx_destroy_image(box->mlx, box->img_42);
	mlx_destroy_window(box->mlx, box->win);
	mlx_destroy_display(box->mlx);
	free(box->mlx);
}

int	count_nums(char **nums, int *check)
{
	int	cols;

	cols = 0;
	while (nums[cols])
		free (nums[cols++]);
	*check = cols;
	return (cols);
}
