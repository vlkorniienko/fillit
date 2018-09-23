/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 10:07:30 by ykaplien          #+#    #+#             */
/*   Updated: 2018/05/04 10:07:32 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	m_del(t_global *figure)
{
	int		x;
	int		y;
	int		z;

	y = 0;
	z = 0;
	while (y < figure->size && z < 4)
	{
		x = 0;
		while (x < figure->size)
		{
			z = 0;
			if (figure->m[y][x] == figure->t[figure->i].field)
			{
				figure->m[y][x] = '.';
				z++;
			}
			x++;
		}
		y++;
	}
}

void	m_set(t_global *f)
{
	f->m[f->yx[0] + f->t[f->i].y[0]][f->yx[1] + f->t[f->i].x[0]] = FIELD;
	f->m[f->yx[0] + f->t[f->i].y[1]][f->yx[1] + f->t[f->i].x[1]] = FIELD;
	f->m[f->yx[0] + f->t[f->i].y[2]][f->yx[1] + f->t[f->i].x[2]] = FIELD;
	f->m[f->yx[0] + f->t[f->i].y[3]][f->yx[1] + f->t[f->i].x[3]] = FIELD;
}

void	map_print(t_global *f)
{
	int l;

	l = 0;
	while (l < f->size)
	{
		ft_putstr(f->m[l++]);
		ft_putchar('\n');
	}
}
