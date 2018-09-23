/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traktor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:06:54 by ykaplien          #+#    #+#             */
/*   Updated: 2018/05/04 08:21:34 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char		*buff;
	t_global	*figure;

	buff = NULL;
	figure = NULL;
	if ((buff = validation(buff, argc, argv)))
	{
		figure = (t_global*)malloc(sizeof(t_global));
		initialization(figure, buff);
		s_fill(figure, buff);
		s_shuffle(figure, buff);
		while (!backtracking(figure))
		{
			map_iter(figure);
			figure->i = 0;
		}
	}
	map_print(figure);
	return (0);
}

void	initialization(t_global *figure, char *buff)
{
	figure->t = (t_elements*)malloc(sizeof(t_elements) * t_count(buff));
	figure->z = t_count(buff);
	figure->size = 2;
	figure->yx[0] = 0;
	figure->yx[1] = 0;
	figure->i = 0;
	map_create(figure);
	map_copy_create(figure);
}

char	*validation(char *buff, int argc, char **argv)
{
	if (arg_count(argc, argv))
		if ((buff = m_read(argv, buff)))
			if (t_validation(buff))
				return (buff);
	return (0);
}
