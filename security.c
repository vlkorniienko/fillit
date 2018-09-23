/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 08:40:06 by vkorniie          #+#    #+#             */
/*   Updated: 2018/05/04 08:40:11 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		arg_count(int argc, char **argv)
{
	argv = NULL;
	if (argc == 2)
		return (1);
	else
		error(1);
	return (0);
}

void	error(int a)
{
	if (a == 1)
	{
		ft_putstr("usage: fillit input_file\n");
		exit(0);
	}
	else if (a == 2)
	{
		ft_putstr("error\n");
		exit(0);
	}
}

char	*m_read(char **argv, char *buff)
{
	int fd;
	int def;

	buff = (char *)malloc(sizeof(char) * 546);
	ft_bzero(buff, 546);
	def = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 1)
		error(2);
	while (read(fd, buff, 545))
		def++;
	if (def != 1)
		error(2);
	return (buff);
}

int		t_validation(char *buff)
{
	int def;
	int tetr_c;
	int i;

	tetr_c = t_count(buff);
	def = 0;
	i = 0;
	while (*buff)
	{
		if (t_newl(buff))
			if (t_smbls(buff))
				if (t_relat(buff))
				{
					def++;
					if (buff[20] == '\n' && i < tetr_c)
						i++;
				}
		buff += 21;
	}
	if (def == tetr_c && i + 1 == def)
		return (1);
	else
		error(2);
	return (0);
}

int		t_newl(char *buff)
{
	if (buff[4] == '\n' && buff[9] == '\n' &&
		buff[14] == '\n' && buff[19] == '\n')
		return (1);
	else
		error(2);
	return (0);
}
