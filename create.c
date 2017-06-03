/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:04:33 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 17:04:35 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem_in		*create_lem(void)
{
	t_lem_in	*lem;

	lem = (t_lem_in *)malloc(sizeof(t_lem_in));
	lem->ant.end = 0;
	lem->ant.nb = 0;
	lem->min = NULL;
	lem->opt = NULL;
	lem->path = NULL;
	lem->room = NULL;
	lem->link = NULL;
	lem->room_start = 0;
	lem->room_end = 0;
	lem->error = 0;
	lem->link_end = 0;
	lem->command = NULL;
	return (lem);
}

void			create_passed_ant(int digit, t_passed **ant_s, int ant, int x)
{
	int			i;
	t_passed	*tmp;

	tmp = *ant_s;
	i = digit;
	while (digit-- > 1)
		tmp = tmp->next;
	while (i <= ant)
	{
		add_passed(&tmp->number, i);
		i += x;
	}
}

void			create_passed(int x, t_passed **ant_s, int ant)
{
	int			i;
	int			x2;

	x2 = x;
	i = 1;
	while (x-- > 0)
	{
		create_passed_room(ant_s);
		create_passed_ant(i, ant_s, ant, x2);
		i++;
	}
}

void			create_passed_room(t_passed **ant_s)
{
	t_passed	*tmp;
	t_passed	*head;

	if (*ant_s == NULL)
	{
		*ant_s = (t_passed *)malloc(sizeof(t_passed));
		(*ant_s)->number = NULL;
		(*ant_s)->next = NULL;
	}
	else
	{
		tmp = (t_passed *)malloc(sizeof(t_passed));
		tmp->number = NULL;
		tmp->next = NULL;
		head = *ant_s;
		while ((*ant_s)->next != NULL)
			*ant_s = (*ant_s)->next;
		(*ant_s)->next = tmp;
		*ant_s = head;
	}
}

void			create_x(t_way_min *path, t_passed *ant, t_x **x)
{
	while (ant != NULL)
	{
		add_x(ant, path, x);
		ant = ant->next;
		path = path->next;
	}
}
