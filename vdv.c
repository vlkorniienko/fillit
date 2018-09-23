/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vdv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 10:08:43 by ykaplien          #+#    #+#             */
/*   Updated: 2018/05/11 12:19:50 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		t_smbls(char *buff)
{
	int ind;
	int dots;
	int hashs;

	dots = 0;
	hashs = 0;
	ind = 0;
	while (ind <= 20)
	{
		if (buff[ind] == '.')
			dots++;
		else if (buff[ind] == '#')
			hashs++;
		ind++;
	}
	if (dots == 12 && hashs == 4)
		return (1);
	error(2);
	return (0);
}

int		t_relat(char *b)
{
	int i;
	int def;

	i = 0;
	def = 0;
	while (i <= 20)
	{
		if (b[i] == '#' && b[i + 1] == '#')
			def++;
		if (b[i] == '#' && b[i + 5] == '#')
			def++;
		i++;
	}
	if (def >= 3)
		return (1);
	error(2);
	return (0);
}

int		t_count(char *buff)
{
	int	count;

	count = (ft_strlen(buff) + 1) / 21;
	return (count);
}

int		col(char *buff)
{
	int	ind;
	int x;
	int def;
	int l;

	def = 0;
	ind = 20;
	x = 1;
	l = 0;
	while (buff[ind * x] && l < t_count(buff))
	{
		if (buff[ind * x] == '\n')
			def++;
		x++;
	}
	if (def + 1 == t_count(buff))
		return (1);
	return (0);
}
