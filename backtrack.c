/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 09:49:33 by ykaplien          #+#    #+#             */
/*   Updated: 2018/05/04 09:49:38 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		backtracking(t_global *figure)
{
	if (figure->i == figure->z)
		return (1);
	figure->yx[0] = 0;
	while (figure->yx[0] < figure->size)
	{
		figure->yx[1] = 0;
		while (figure->yx[1] < figure->size)
		{
			if (m_dot(figure))
			{
				figure->t[figure->i].yx[0] = figure->yx[0];
				figure->t[figure->i].yx[1] = figure->yx[1];
				figure->i++;
				if (!backtracking(figure))
					backtracking_help(figure);
				else
				{
					return (1);
				}
			}
			figure->yx[1]++;
		}
		figure->yx[0]++;
	}
	return (0);
}

void	backtracking_help(t_global *figure)
{
	figure->i--;
	m_del(figure);
	figure->yx[0] = figure->t[figure->i].yx[0];
	figure->yx[1] = figure->t[figure->i].yx[1];
}

void	map_iter(t_global *figure)
{
	figure->size++;
	map_create(figure);
	figure->yx[0] = 0;
	figure->yx[1] = 0;
	figure->i = 0;
}

void	map_create(t_global *f)
{
	int		k;

	k = 0;
	if ((f->m = (char **)malloc(sizeof(char *) * (f->size + 1))))
	{
		while (k < f->size)
		{
			f->m[k] = (char *)malloc(sizeof(char) * f->size + 1);
			f->m[k][f->size] = '\0';
			k++;
		}
		f->m[f->size] = NULL;
	}
	map_set(f);
}

void	map_copy_create(t_global *f)
{
	int		k;

	k = 0;
	if ((f->m_copy = (char **)malloc(sizeof(char *) * (f->size + 1))))
	{
		while (k < f->size)
		{
			f->m_copy[k] = (char *)malloc(sizeof(char) * f->size + 1);
			f->m_copy[k][f->size] = '\0';
			k++;
		}
		f->m_copy[f->size] = NULL;
	}
	m_copy_set(f);
}
