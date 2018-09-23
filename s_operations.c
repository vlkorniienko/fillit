/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 09:49:59 by ykaplien          #+#    #+#             */
/*   Updated: 2018/05/04 09:50:02 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	s_fill(t_global *figure, char *buff)
{
	int		ind;
	int		i;
	int		j;
	char	letter;

	i = 0;
	j = 0;
	letter = 'A';
	while (*buff)
	{
		ind = -1;
		while (ind <= 20)
		{
			if (buff[++ind] == '#' && j < 4)
			{
				figure->t[i].x[j] = ind % 5;
				figure->t[i].y[j] = ind / 5;
				j++;
			}
		}
		figure->t[i].field = letter++;
		i++;
		j = 0;
		buff += 21;
	}
}

void	s_shuffle(t_global *figure, char *buff)
{
	int i;
	int col;

	i = 0;
	col = t_count(buff);
	while (i < col)
	{
		s_shuffle_x(figure, i);
		s_shuffle_y(figure, i);
		i++;
	}
}

void	s_shuffle_x(t_global *figure, int i)
{
	while (figure->t[i].x[0] != 0)
	{
		figure->t[i].x[0]--;
		figure->t[i].x[1]--;
		figure->t[i].x[2]--;
		figure->t[i].x[3]--;
	}
}

void	s_shuffle_y(t_global *figure, int i)
{
	while (figure->t[i].y[0] != 0)
	{
		figure->t[i].y[0]--;
		figure->t[i].y[1]--;
		figure->t[i].y[2]--;
		figure->t[i].y[3]--;
	}
}
