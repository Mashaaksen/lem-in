/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:48:12 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 15:48:14 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			sum_room(char *next, t_link *link)
{
	int		i;

	i = 0;
	while (link != NULL)
	{
		if (!ft_strcmp(next, link->x) || !ft_strcmp(next, link->y))
			i++;
		link = link->next;
	}
	return (i);
}

int			find_in_way(t_way *way, t_link *link, int x, int y)
{
	while (way != NULL)
	{
		if ((x == 0 && !ft_strcmp(link->y, way->room)) ||
				(y == 0 && !ft_strcmp(way->room, link->x)))
			return (1);
		way = way->next;
	}
	return (0);
}

void		free_last(t_way **way)
{
	t_way	*tmp;
	t_way	*p;

	tmp = *way;
	p = tmp->next;
	while (p && p->next)
	{
		tmp = tmp->next;
		p = p->next;
	}
	tmp->next = NULL;
	free(p->room);
	free(p);
}

int			find_first_way(t_way *way, t_link *link, char *end, int len)
{
	int		flag;
	char	*next;
	int		i;

	flag = 0;
	i = -1;
	while (++i < len && flag == 0)
	{
		next = find_next(link, way, i);
		if (next == NULL || !ft_strcmp(next, end))
		{
			next != NULL ? free(next) : 0;
			return (next == NULL ? 0 : 1);
		}
		else
		{
			flag = find_first_way(add_way(way, next), link, end,
				sum_room(next, link));
			free(next);
		}
		free_last(&way);
	}
	(flag == 1 && way->next == NULL) ? free(way->room) : 0;
	(flag == 1 && way->next == NULL) ? free(way) : 0;
	return (flag);
}

void		valid_way(t_room *room, t_link *link)
{
	char	*next;
	char	*end;
	t_way	*way;
	int		i;

	way = NULL;
	find_start_end(room, &next, &end);
	i = find_first_way(add_way(way, next), link, end, sum_room(next, link));
	free(next);
	free(end);
	if (i == 0)
		error();
}
