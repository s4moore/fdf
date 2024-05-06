/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:48:59 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 18:23:33 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define __USE_MISC
#include "./../libraries/fdf.h"

void	init_mlx(t_box *box)
{
	void	*tmp;

	box->mlx = mlx_init();
	if (!box->mlx)
		exit (1);
	box->win = mlx_new_window(box->mlx, WIDE, HIGH, "Fdf");
	if (!box->win)
	{
		mlx_destroy_display(box->mlx);
		free (box->mlx);
		exit (2);
	}
	read_42(box);
	make_banner(box);
	box->img = mlx_new_image(box->mlx, WIDE, HIGH);
	tmp = mlx_get_data_addr(box->img, &box->bpp, &box->line_len, &box->e);
	box->img_ptr = tmp;
	box->bpp_offset = box->bpp / 8;
	box->pong = 0;
	box->colour_scheme = 0;
}

void	add_map(t_box *box, char *file)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char *) * (box->num_maps + 1));
	while (i < box->num_maps)
	{
		tmp[i] = box->map_names[i];
		i++;
	}
	tmp[i] = ft_strdup(file);
	free (box->map_names);
	box->map_names = tmp;
	box->start_map = box->num_maps++;
}

void	make_map_names(t_box *box)
{
	box->map_names = malloc(sizeof(char *) * box->num_maps);
	box->map_names[0] = ft_strdup("./maps/42.fdf");
	box->map_names[1] = ft_strdup("./maps/50-4.fdf");
	box->map_names[2] = ft_strdup("./maps/100-6.fdf");
	box->map_names[3] = ft_strdup("./maps/basictest.fdf");
	box->map_names[4] = ft_strdup("./maps/elem.fdf");
	box->map_names[5] = ft_strdup("./maps/elem2.fdf");
	box->map_names[6] = ft_strdup("./maps/elem-col.fdf");
	box->map_names[7] = ft_strdup("./maps/julia.fdf");
	box->map_names[8] = ft_strdup("./maps/mars.fdf");
	box->map_names[9] = ft_strdup("./maps/pyr.fdf");
	box->map_names[10] = ft_strdup("./maps/pyra.fdf");
	box->map_names[11] = ft_strdup("./maps/pyramide.fdf");
	box->map_names[12] = ft_strdup("./maps/t1.fdf");
	box->map_names[13] = ft_strdup("./maps/t2.fdf");
}

int	set_map_number(t_box *box, char *file)
{
	char	*f_name;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < box->num_maps)
	{
		j = 0;
		k = 0;
		f_name = box->map_names[i];
		while (f_name[j] && file[k] && f_name[j] == file[k])
		{
			j++;
			k++;
		}
		if (!file[k])
		{
			box->start_map = i;
			return (0);
		}
		i++;
	}
	return (1);
}

void	make_maps(t_box *box, char *file)
{
	int	i;

	i = 0;
	box->map = malloc(sizeof(t_prjct *) * box->num_maps);
	while (i < box->num_maps)
	{
		box->map[i] = malloc(sizeof(t_prjct) * 2);
		i++;
	}
	prepare_maps(box);
	i = 0;
	while (i < box->num_maps)
	{
		box->reset_join_globe = 1;
		box->reset_join_flat = 1;
		box->reset_points_index = 1;
		box->m = i;
		read_map(box, box->map_names[i], box->m);
		box->map[box->m][0].edges = make_flat_map(box);
		box->map[box->m][1].edges = make_globe_map(box);
		make_sphere(box, box->map[box->m][1].zoom);
		i++;
	}
	make_colour_maps(box);
}
