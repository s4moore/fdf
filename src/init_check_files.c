/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:21:05 by samoore           #+#    #+#             */
/*   Updated: 2024/03/18 18:21:09 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

static int	num_lines(char *file)
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

static char	*re_alloc(char *str, int *size)
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

static char	*gnl(int fd)
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

static int	gnl_check(t_box *box, int fd, int rows)
{
	char	**nums;
	char	*str;
	int		i;
	int		cols;
	int		check;

	i = 0;
	cols = 0;
	while (i < rows)
	{
		check = 0;
		str = gnl(fd);
		nums = ft_split_space(str);
		if (cols == 0)
			cols = count_nums(nums, &check);
		else
			while (nums[check])
				free (nums[check++]);
		free (nums);
		if (check != cols)
			return (1);
		i++;
	}
	return (0);
}

void	check_maps(t_box *box, char *file)
{
	int	i;
	int	fd;
	int	rows;

	i = 0;
	while (i < box->num_maps)
	{
		rows = num_lines(box->map_names[i]);
		fd = open(box->map_names[i], O_RDONLY);
		if (fd == -1)
		{
			perror("file error");
			exit (1);
		}
		if (gnl_check(box, fd, rows))
		{
			check_free(box, file);
			exit (2);
		}
		close(fd);
		i++;
	}
}
