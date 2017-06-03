/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_way.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:56:15 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 16:56:17 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				count_myway(t_way *way)
{
	int			i;

	i = 0;
	while (way != NULL)
	{
		way = way->next;
		i++;
	}
	return (i);
}

t_way			*dup_way(t_way *way, int len)
{
	t_way		*head;

	head = NULL;
	while (len-- > 0)
	{
		head = add_way(head, way->room);
		way = way->next;
	}
	return (head);
}

void			ant_way(t_way_min **min, t_way *way)
{
	t_way_min	*tmp;
	t_way_min	*head;
	int			x;

	x = count_myway(way);
	if (*min == NULL)
	{
		*min = (t_way_min *)malloc(sizeof(t_way_min));
		(*min)->next = NULL;
		(*min)->x = x;
		(*min)->min = dup_way(way, x);
	}
	else
	{
		tmp = (t_way_min *)malloc(sizeof(t_way_min));
		tmp->next = NULL;
		tmp->x = x;
		tmp->min = dup_way(way, x);
		head = *min;
		while ((*min)->next != NULL)
			*min = (*min)->next;
		(*min)->next = tmp;
		*min = head;
	}
}

int				find_min_way(t_way_min **min, t_way *way, t_end *p, int len)
{
	char		*next;
	int			i;

	i = -1;
	while (++i < len)
	{
		next = find_next(p->link, way, i);
		if (next == NULL)
			return (0);
		if (!ft_strcmp(next, p->str))
			ant_way(min, add_way(way, next));
		else
			find_min_way(min, add_way(way, next), p,
				sum_room(next, p->link));
		free(next);
		free_last(&way);
	}
	if (way->next == NULL)
	{
		free(way->room);
		free(way);
	}
	return (0);
}

t_way_min		*min_way(t_room *room, t_link *link)
{
	char		*next;
	t_end		*p;
	t_way		*way;
	t_way_min	*min;

	way = NULL;
	p = (t_end *)malloc(sizeof(t_end));
	p->link = link;
	find_start_end(room, &next, &p->str);
	min = NULL;
	find_min_way(&min, add_way(way, next), p, sum_room(next, link));
	free(next);
	free(p->str);
	free(p);
	return (min);
}
