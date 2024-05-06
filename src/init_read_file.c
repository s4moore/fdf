/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_read_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:39:41 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 17:31:35 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

int	num_lines(char *file)
{
	char	c;
	int		fd;
	int		res;
	int		bytes;

	res = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		exit (1);
	}
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, &c, 1);
		if (c == '\n')
			res++;
	}
	close (fd);
	return (res - 1);
}

char	*re_alloc(char *str, int *size)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * *size * 2);
	while (i < *size)
	{
		res[i] = str[i];
		i++;
	}
	*size *= 2;
	free (str);
	return (res);
}

char	*gnl(int fd)
{
	char	*res;
	char	c;
	int		i;
	int		size;
	int		bytes;

	size = 128;
	bytes = 1;
	i = 0;
	res = malloc(sizeof(char) * size);
	while (bytes > 0)
	{
		bytes = read(fd, &c, 1);
		if (i == size - 2)
			res = re_alloc(res, &size);
		if (!c || c == '\n')
		{
			res[i] = 0;
			return (res);
		}
		res[i++] = c;
	}
	free (res);
	return (NULL);
}

void	gnl_loop(t_box *box, int fd, int m)
{
	char		**nums;
	char		*str;
	int			i;
	int			cols_rows;

	i = 0;
	while (i < box->map[m][0].rows)
	{
		str = gnl(fd);
		nums = ft_split_space(str);
		if (box->map[m][0].cols == 0)
		{
			while (nums[box->map[m][0].cols])
				box->map[m][0].cols++;
			cols_rows = box->map[m][0].cols * box->map[m][0].rows;
			box->map[m][0].points = ft_calloc(sizeof(t_point), cols_rows + 1);
			box->map[m][1].points = ft_calloc(sizeof(t_point), cols_rows + 1);
		}
		store_z_values(box, nums, i);
		i++;
	}
	store_x_y_values(box);
}

void	read_map(t_box *box, char *file, int m)
{
	int		fd;

	box->map[m][0].cols = 0;
	box->map[m][0].rows = num_lines(file);
	fd = open(file, O_RDONLY);
	gnl_loop(box, fd, m);
	close(fd);
}
