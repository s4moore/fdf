/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:44:51 by samoore           #+#    #+#             */
/*   Updated: 2024/03/15 18:00:57 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libraries/fdf.h"

void	join(t_box *box, int start, int end, t_edge *edge)
{
	edge->start = &box->map[box->m][box->p].points[start];
	edge->end = &box->map[box->m][box->p].points[end];
}

void	join_flat_points(t_box *box, int i, int j, t_edge *res)
{
	static int	edge = 0;
	int			pos;

	if (box->reset_join_flat)
	{
		edge = 0;
		box->reset_join_flat = 0;
	}
	pos = i * box->map[box->m][0].cols + j;
	if (j < box->map[box->m][0].cols - 1)
		join(box, pos, pos + 1, &res[edge++]);
	if (i < box->map[box->m][0].rows - 1 && j < box->map[box->m][0].cols)
		join(box, pos, pos + box->map[box->m][0].cols, &res[edge++]);
	box->map[box->m][0].num_edges = edge;
}

void	join_globe_points(t_box *box, int i, int j, t_edge *res)
{
	static int	edge = 0;
	int			pos;

	if (box->reset_join_globe)
	{
		edge = 0;
		box->reset_join_globe = 0;
	}
	pos = i * box->map[box->m][0].cols + j;
	if (j < box->map[box->m][0].cols - 1)
		join(box, pos, pos + 1, &res[edge++]);
	else
		join(box, pos - 1, pos - box->map[box->m][0].cols + 1, &res[edge++]);
	if (i < box->map[box->m][0].rows - 1 && j < box->map[box->m][0].cols - 1)
		join(box, pos, pos + box->map[box->m][0].cols, &res[edge++]);
	box->map[box->m][1].num_edges = edge;
}

t_edge	*make_flat_map(t_box *box)
{
	t_edge	*res;
	int		i;
	int		j;

	res = ft_calloc(sizeof(t_edge), box->map[box->m][0].num_pts * 2);
	if (!res)
		exit (3);
	i = 0;
	box->p = 0;
	while (i < box->map[box->m][0].rows)
	{
		j = 0;
		while (j < box->map[box->m][0].cols)
			join_flat_points(box, i, j++, res);
		i++;
	}
	i = 0;
	return (res);
}

t_edge	*make_globe_map(t_box *box)
{
	t_edge	*res;
	int		i;
	int		j;
	int		num_pts;

	num_pts = box->map[box->m][0].num_pts;
	res = ft_calloc(sizeof(t_edge), num_pts * 2 + box->map[box->m][0].rows);
	if (!res)
		exit (3);
	i = 0;
	box->p = 1;
	while (i < box->map[box->m][0].rows)
	{
		j = 0;
		while (j <= box->map[box->m][0].cols)
			join_globe_points(box, i, j++, res);
		i++;
	}
	return (res);
}
