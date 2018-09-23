/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmoves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 10:05:42 by ykaplien          #+#    #+#             */
/*   Updated: 2018/05/04 10:05:43 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	map_set(t_global *f)
{
	int		k;
	int		l;

	k = 0;
	while (k < f->size)
	{
		l = 0;
		while (l < f->size)
		{
			f->m[k][l] = '.';
			l++;
		}
		k++;
	}
}

void	m_copy_set(t_global *f)
{
	int		k;
	int		l;

	k = 0;
	while (k < f->size)
	{
		l = 0;
		while (l < f->size)
		{
			f->m_copy[k][l] = '.';
			l++;
		}
		k++;
	}
}

int		m_dot(t_global *f)
{
	int		x;
	int		y;

	y = f->yx[0];
	x = f->yx[1];
	while (y < f->size)
	{
		while (x < f->size)
		{
			if (x == f->size - 1 && y == f->size - 1)
				return (0);
			if (f->m[y][x] == '.')
			{
				if (x == f->size - 1 && y == f->size - 1 && f->i == 0)
					return (0);
				if (m_dot_help(f, x, y))
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int		m_dot_help(t_global *f, int x, int y)
{
	if (m_check(f))
	{
		f->yx[0] = y;
		f->yx[1] = x;
		return (1);
	}
	return (0);
}

int		m_check(t_global *f)
{
	int		count;

	count = 0;
	if (f->yx[0] + f->t[f->i].y[0] < f->size
		&& f->yx[1] + f->t[f->i].x[0] < f->size
		&& f->m[f->yx[0] + f->t[f->i].y[0]][f->yx[1] + f->t[f->i].x[0]] == '.')
		count++;
	if (f->yx[0] + f->t[f->i].y[1] < f->size
		&& f->yx[1] + f->t[f->i].x[1] < f->size
		&& f->m[f->yx[0] + f->t[f->i].y[1]][f->yx[1] + f->t[f->i].x[1]] == '.')
		count++;
	if (f->yx[0] + f->t[f->i].y[2] < f->size
		&& f->yx[1] + f->t[f->i].x[2] < f->size
		&& f->m[f->yx[0] + f->t[f->i].y[2]][f->yx[1] + f->t[f->i].x[2]] == '.')
		count++;
	if (f->yx[0] + f->t[f->i].y[3] < f->size
		&& f->yx[1] + f->t[f->i].x[3] < f->size
		&& f->m[f->yx[0] + f->t[f->i].y[3]][f->yx[1] + f->t[f->i].x[3]] == '.')
		count++;
	if (count == 4)
	{
		m_set(f);
		return (1);
	}
	return (0);
}
