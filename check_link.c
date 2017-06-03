/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:41:26 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 17:41:27 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_name_room(t_room *room, char *x, char *y)
{
	int		flag1;
	int		flag2;

	flag1 = 0;
	flag2 = 0;
	while (room != NULL)
	{
		if (!ft_strcmp(room->name, x))
			flag1++;
		else if (!ft_strcmp(room->name, y))
			flag2++;
		room = room->next;
	}
	return ((flag1 == 1 && flag2 == 1) ? 0 : 1);
}

void		check_link(t_lem_in **lem, t_room *room, char *x, char *y)
{
	if (check_name_room(room, x, y) != 0)
		(*lem)->error = 1;
	else
		(*lem)->link_end = 1;
}
