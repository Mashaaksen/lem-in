/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_way.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:23:07 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 16:23:26 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				find_cpy(t_way *orig, t_way *tmp, char *end, char *start)
{
	t_way		*p;

	while (orig != NULL)
	{
		p = tmp;
		while (p != NULL)
		{
			if (!ft_strcmp(orig->room, p->room) && ft_strcmp(orig->room, end)
				&& ft_strcmp(orig->room, start))
				return (1);
			p = p->next;
		}
		orig = orig->next;
	}
	return (0);
}

int				sum_opt(t_way_min *min, char *end, char *start)
{
	int			len;
	t_way		*way;
	t_way		*tmp;

	way = min->min;
	len = 1;
	while (min != NULL)
	{
		tmp = min->min;
		if (find_cpy(way, tmp, end, start) == 0)
			len++;
		min = min->next;
	}
	return (len);
}

void			add_opt(t_way_min *min, t_way_opt **opt, t_room *room)
{
	int			len;
	int			i;
	char		*end;
	char		*start;

	i = -1;
	find_start_end(room, &start, &end);
	len = sum_opt(min, end, start);
	while (++i < len)
		add_opt_min(min, opt, room, i);
	free(start);
	free(end);
}

void			add_pathways(t_way_min **head, t_way_min *all_pathways)
{
	t_way_min	*tmp;
	t_way_min	*p;

	if (*head == NULL)
	{
		*head = (t_way_min *)malloc(sizeof(t_way_min));
		(*head)->min = dup_way(all_pathways->min, all_pathways->x);
		(*head)->x = all_pathways->x;
		(*head)->next = NULL;
	}
	else
	{
		tmp = (t_way_min *)malloc(sizeof(t_way_min));
		tmp->min = dup_way(all_pathways->min, all_pathways->x);
		tmp->x = all_pathways->x;
		tmp->next = NULL;
		p = *head;
		while ((*head)->next != NULL)
			*head = (*head)->next;
		(*head)->next = tmp;
		*head = p;
	}
}

t_way_opt		*opt_way(t_way_min *all_pathways, t_room *room)
{
	t_way_opt	*opt;
	t_way_min	*head;
	t_way_min	*tmp;

	opt = NULL;
	while (all_pathways != NULL)
	{
		head = dup_pathways(all_pathways);
		add_opt(head, &opt, room);
		while (head != NULL)
		{
			tmp = head->next;
			free_way_min(&head);
			head = tmp;
		}
		all_pathways = all_pathways->next;
	}
	return (opt);
}
