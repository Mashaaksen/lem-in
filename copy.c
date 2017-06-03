/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:28:32 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 17:28:33 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				add_passed(t_passed_room **number, int nb)
{
	t_passed_room	*tmp;
	t_passed_room	*head;

	if (*number == NULL)
	{
		*number = (t_passed_room *)malloc(sizeof(t_passed_room));
		(*number)->digit = nb;
		(*number)->status = 1;
		(*number)->next = NULL;
	}
	else
	{
		tmp = (t_passed_room *)malloc(sizeof(t_passed_room));
		tmp->digit = nb;
		tmp->status = 1;
		tmp->next = NULL;
		head = *number;
		while ((*number)->next != NULL)
			*number = (*number)->next;
		(*number)->next = tmp;
		*number = head;
	}
}

void				add_x(t_passed *ant, t_way_min *path, t_x **x)
{
	t_x				*tmp;
	t_x				*head;

	if (*x == NULL)
	{
		*x = (t_x *)malloc(sizeof(t_x));
		(*x)->next = NULL;
		(*x)->len = path->x;
		(*x)->number = ant->number;
		(*x)->path = path->min;
	}
	else
	{
		tmp = (t_x *)malloc(sizeof(t_x));
		tmp->next = NULL;
		tmp->len = path->x;
		tmp->number = ant->number;
		tmp->path = path->min;
		head = *x;
		while ((*x)->next != NULL)
			*x = (*x)->next;
		(*x)->next = tmp;
		*x = head;
	}
}

void				ant_in_link(t_way_min *pathway, int ant, int n)
{
	t_passed		*ant_s;
	t_x				*x;

	x = NULL;
	ant_s = NULL;
	create_passed(n, &ant_s, ant);
	create_x(pathway, ant_s, &x);
	print_x(x);
	free_ant_s(&ant_s);
	free_x(&x);
}

t_way_min			*dup_pathways(t_way_min *all_pathways)
{
	t_way_min		*head;

	head = NULL;
	while (all_pathways != NULL)
	{
		add_pathways(&head, all_pathways);
		all_pathways = all_pathways->next;
	}
	return (head);
}
