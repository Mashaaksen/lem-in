/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:05:03 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 16:05:05 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				print_ant_in_link(char *str, int nb)
{
	ft_putstr(BLU);
	ft_putstr(" ");
	ft_putstr("L");
	ft_putnbr(nb);
	ft_putstr("-");
	ft_putstr(str);
	ft_putstr(" ");
	ft_putstr(END);
}

int					check_number(t_x *x)
{
	t_passed_room	*tmp;

	while (x != NULL)
	{
		tmp = x->number;
		while (tmp != NULL)
		{
			if (tmp->status < x->len)
				return (0);
			tmp = tmp->next;
		}
		x = x->next;
	}
	return (1);
}

char				*find_str(t_way *path, int i)
{
	while (i-- > 0)
		path = path->next;
	return (path->room);
}

void				try_print(t_x *tmp)
{
	int				step;
	t_passed_room	*p;
	int				flag;

	flag = 0;
	p = tmp->number;
	while (flag != 2 && p != NULL)
	{
		while (p && p->status == tmp->len)
			p = p->next;
		if (!p)
			break ;
		step = p->status;
		print_ant_in_link(find_str(tmp->path, p->status++), p->digit);
		p = p->next;
		if (p != NULL)
			flag = (step == p->status ? 2 : 1);
	}
}

void				print_x(t_x *x)
{
	int				flag;
	t_x				*tmp;

	flag = 0;
	while (flag == 0)
	{
		tmp = x;
		while (tmp != NULL)
		{
			try_print(tmp);
			tmp = tmp->next;
		}
		flag = check_number(x);
		ft_putstr("\n");
	}
}
