/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_some_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:02:52 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 17:02:54 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char				*find_next(t_link *link, t_way *way, int i)
{
	t_way			*tmp;

	tmp = way;
	while (way->next != NULL)
		way = way->next;
	while (link != NULL)
	{
		if (!ft_strcmp(way->room, link->x) || !ft_strcmp(way->room, link->y))
			if (find_in_way(tmp, link, ft_strcmp(way->room, link->x),
				ft_strcmp(way->room, link->y)) == 0)
			{
				i--;
				if (i == -1)
					return (!ft_strcmp(way->room, link->x) ? ft_strdup(link->y)
						: ft_strdup(link->x));
			}
		link = link->next;
	}
	return (NULL);
}

void				find_start_end(t_room *room, char **start, char **end)
{
	while (room != NULL)
	{
		if (start != NULL && !ft_strcmp("start_room", room->line))
			*start = ft_strdup(room->name);
		else if (end != NULL && !ft_strcmp("end_room", room->line))
			*end = ft_strdup(room->name);
		room = room->next;
	}
}
