/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:00:43 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 17:00:45 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				free_char(char **arr)
{
	char			*str;
	char			**a;

	a = arr;
	while (*arr != NULL)
	{
		str = *arr;
		free(str);
		arr++;
	}
	free(a);
}

void				free_way_min(t_way_min **way)
{
	t_way			*p;

	while ((*way)->min != NULL)
	{
		p = (*way)->min->next;
		(*way)->min->next = NULL;
		free((*way)->min->room);
		free((*way)->min);
		(*way)->min = p;
	}
	(*way)->next = NULL;
	free(*way);
}

void				free_ant_s(t_passed **ant_s)
{
	t_passed		*tmp;
	t_passed_room	*p;

	while (*ant_s != NULL)
	{
		tmp = (*ant_s)->next;
		while ((*ant_s)->number != NULL)
		{
			p = (*ant_s)->number->next;
			(*ant_s)->number->next = NULL;
			free((*ant_s)->number);
			(*ant_s)->number = p;
		}
		(*ant_s)->next = NULL;
		free(*ant_s);
		*ant_s = tmp;
	}
}

void				free_x(t_x **x)
{
	t_x				*tmp;
	t_way			*way;

	while (*x != NULL)
	{
		tmp = (*x)->next;
		while ((*x)->path != NULL)
		{
			way = (*x)->path->next;
			(*x)->path->next = NULL;
			free((*x)->path->room);
			free((*x)->path);
			(*x)->path = way;
		}
		(*x)->next = NULL;
		free(*x);
		*x = tmp;
	}
}
