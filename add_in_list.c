/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 18:14:58 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 18:14:59 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			add_str(t_lem_in **lem, char **a, char *line)
{
	t_room		*tmp;
	t_room		*head;

	tmp = (t_room *)malloc(sizeof(t_room));
	tmp->next = NULL;
	tmp->line = ft_strdup(line);
	tmp->name = ft_strdup(a[0]);
	tmp->x = ft_atoi(a[1]);
	tmp->y = ft_atoi(a[2]);
	if ((*lem)->room == NULL)
		(*lem)->room = tmp;
	else
	{
		head = (*lem)->room;
		while ((*lem)->room->next != NULL)
			(*lem)->room = (*lem)->room->next;
		(*lem)->room->next = tmp;
		(*lem)->room = head;
	}
	check_room(a, lem, line);
}

void			add_link(t_lem_in **lem, char **a, t_link *tmp, t_link *head)
{
	tmp = (t_link *)malloc(sizeof(t_link));
	tmp->x = ft_strdup(a[0]);
	tmp->y = ft_strdup(a[1]);
	tmp->next = NULL;
	check_link(lem, (*lem)->room, tmp->x, tmp->y);
	if ((*lem)->error == 0 && (*lem)->link == NULL)
		(*lem)->link = tmp;
	else if ((*lem)->error == 0)
	{
		head = (*lem)->link;
		while ((*lem)->link->next != NULL)
			(*lem)->link = (*lem)->link->next;
		(*lem)->link->next = tmp;
		(*lem)->link = head;
	}
	else
	{
		free(tmp->x);
		free(tmp->y);
		free(tmp);
	}
	free_char(a);
	(*lem)->error != 0 ? valid(*lem) : 0;
}

t_way			*add_way(t_way *way, char *str)
{
	t_way		*tmp;
	t_way		*head;

	if (way == NULL)
	{
		way = (t_way *)malloc(sizeof(t_way));
		way->next = NULL;
		way->room = ft_strdup(str);
	}
	else
	{
		tmp = (t_way *)malloc(sizeof(t_way));
		tmp->next = NULL;
		tmp->room = ft_strdup(str);
		head = way;
		while (way->next != NULL)
			way = way->next;
		way->next = tmp;
		way = head;
	}
	return (way);
}

void			add_command(t_lem_in **lem, char *str, int flag)
{
	t_command	*tmp;
	t_command	*head;

	tmp = (t_command *)malloc(sizeof(t_command));
	tmp->str = ft_strdup(str);
	tmp->flag = flag;
	tmp->next = NULL;
	if ((*lem)->command == NULL)
		(*lem)->command = tmp;
	else
	{
		head = (*lem)->command;
		while ((*lem)->command->next != NULL)
			(*lem)->command = (*lem)->command->next;
		(*lem)->command->next = tmp;
		(*lem)->command = head;
	}
}
