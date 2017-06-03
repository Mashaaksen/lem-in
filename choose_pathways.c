/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_pathways.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:34:27 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 17:34:28 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				find_way_min(t_way_opt *opt, int ant)
{
	int			i;

	i = 0;
	while (opt != NULL)
	{
		if (i < opt->x && opt->x <= ant)
			i = opt->x;
		opt = opt->next;
	}
	return (i);
}

int				sum_opt_min(t_way_min *min)
{
	int			len;

	len = 0;
	while (min != NULL)
	{
		len += min->x;
		min = min->next;
	}
	return (len);
}

void			find_len(t_way_opt *opt, int min_way, int *len)
{
	int			i;
	int			min;

	i = 0;
	min = 2147483647;
	while (opt != NULL)
	{
		if (opt->x == min_way && min > sum_opt_min(opt->min))
		{
			min = sum_opt_min(opt->min);
			*len = i;
		}
		i++;
		opt = opt->next;
	}
}

t_way_opt		*find_min_pathways(int min_way, t_way_opt *opt, int len)
{
	t_way_opt	*pathways;
	t_way_opt	*tmp;
	t_way_min	*p;

	pathways = opt;
	find_len(opt, min_way, &len);
	while (len-- > 0)
		pathways = pathways->next;
	opt = pathways->next;
	pathways->next = NULL;
	while (opt != NULL)
	{
		tmp = opt->next;
		while (opt->min != NULL)
		{
			p = opt->min->next;
			free_way_min(&opt->min);
			opt->min = p;
		}
		opt->next = NULL;
		free(opt);
		opt = tmp;
	}
	return (pathways);
}

t_way_opt		*choose_pathways(t_way_opt *opt, int ant)
{
	t_way_opt	*pathways;
	int			min_way;

	min_way = find_way_min(opt, ant);
	pathways = find_min_pathways(min_way, opt, 0);
	return (pathways);
}
