/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_opt_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 18:06:26 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 18:06:27 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				way_cpy(t_way_min *min, int i, char *end, char *start)
{
	int			digit;
	t_way_min	*tmp;
	t_way		*way;
	t_way		*p;

	tmp = min;
	digit = i;
	while (i-- > 0 && tmp->next != NULL)
		tmp = tmp->next;
	p = tmp->min;
	while (digit-- > 0 && min != NULL)
	{
		way = min->min;
		while (way != NULL)
		{
			if (last_el(way->room, p, end, start) == 1)
				return (1);
			way = way->next;
		}
		min = min->next;
	}
	return (0);
}

int				count_opt(t_way_min *min)
{
	int			i;

	i = 0;
	while (min != NULL)
	{
		i++;
		min = min->next;
	}
	return (i);
}

void			free_list(t_way_min **p, t_way_min **min, t_way_min *tmp)
{
	t_way_min	*s;

	free_way_min(p);
	while (*min != NULL)
	{
		s = (*min)->next;
		free_way_min(min);
		*min = s;
	}
	*min = tmp;
}

void			sort_opt(t_way_min **min, char *end, char *start, int len)
{
	t_way_min	*p;
	t_way_min	*tmp;
	t_way_min	*min_way;
	int			i;

	min_way = *min;
	*min = (*min)->next;
	p = min_way;
	i = 0;
	while (p->next != NULL)
	{
		if (way_cpy(min_way, i, end, start) == 1 || (len > 0 && i != 0))
		{
			way_cpy(min_way, i, end, start) == 0 ? len-- : 0;
			tmp = dup_pathways(*min);
			free_list(&p->next, min, tmp);
			p->next = *min;
			i--;
		}
		else if (i != 0)
			p = p->next;
		*min != NULL ? *min = (*min)->next : 0;
		i++;
	}
	*min = min_way;
}

void			add_opt_min(t_way_min *min, t_way_opt **opt, t_room *room,
	int i)
{
	t_way_opt	*tmp;
	t_way_opt	*head;
	t_way_min	*p;
	char		*start;
	char		*end;

	find_start_end(room, &start, &end);
	p = dup_pathways(min);
	sort_opt(&p, end, start, i);
	tmp = (t_way_opt *)malloc(sizeof(t_way_opt));
	tmp->next = NULL;
	tmp->min = p;
	tmp->x = count_opt(p);
	if (*opt == NULL)
		*opt = tmp;
	else
	{
		head = *opt;
		while ((*opt)->next != NULL)
			*opt = (*opt)->next;
		(*opt)->next = tmp;
		*opt = head;
	}
	free(start);
	free(end);
}
