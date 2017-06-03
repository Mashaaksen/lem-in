/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:05:21 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 17:05:23 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		count_list(char **arr)
{
	int	i;

	i = 0;
	while (*arr != NULL)
	{
		i++;
		arr++;
	}
	return (i);
}

int		last_el(char *room, t_way *last, char *start, char *end)
{
	while (last != NULL)
	{
		if (!ft_strcmp(room, last->room) &&
			ft_strcmp(room, end) && ft_strcmp(room, start))
			return (1);
		last = last->next;
	}
	return (0);
}
