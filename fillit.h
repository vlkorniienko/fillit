/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:49:12 by ykaplien          #+#    #+#             */
/*   Updated: 2018/05/04 09:16:49 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define FIELD f->t[f->i].field

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_elements
{
	int				x[4];
	int				y[4];
	int				yx[2];
	char			field;
}					t_elements;

typedef struct		s_global
{
	t_elements		*t;
	int				size;
	int				yx[2];
	int				i;
	int				z;
	char			**m;
	char			**m_copy;
}					t_global;

int					arg_count(int argc, char **argv);
void				error(int a);
char				*m_read(char **argv, char *buff);
int					t_validation(char *buff);
int					t_newl(char *buff);
int					t_smbls(char *buff);
int					t_relat(char *b);
int					t_count(char *buff);
char				*validation(char *buff, int argc, char **argv);
void				ft_bzero(void *s, int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
int					ft_strlen(char *s);
void				s_fill(t_global *figure, char *buff);
void				s_shuffle(t_global *figure, char *buff);
void				s_shuffle_x(t_global *figure, int i);
void				s_shuffle_y(t_global *figure, int i);
int					m_dot(t_global *f);
int					m_dot_help(t_global *f, int x, int y);
int					m_check(t_global *f);
void				m_set(t_global *f);
void				backtracking_help(t_global *figure);
void				map_iter(t_global *figure);
void				initialization(t_global *figure, char *buff);
int					backtracking(t_global *figure);
void				map_create(t_global *f);
void				map_copy_create(t_global *f);
void				map_set(t_global *f);
void				m_copy_set(t_global *f);
void				m_del(t_global *figure);
void				map_print(t_global *f);
int					col(char *buff);

#endif
