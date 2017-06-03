/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_valid_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:09:31 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 16:09:32 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_ant(t_command **tmp, t_ant ant, int *flag)
{
	if (*tmp && (*tmp)->flag == *flag)
	{
		ft_putstr((*tmp)->str);
		ft_putstr("\n");
		*tmp = (*tmp)->next;
		(*flag)++;
	}
	ft_putnbr(ant.nb);
	ft_putstr("\n");
	(*flag)++;
}

void			print_room(t_command **tmp, t_room *room, int *flag)
{
	while (room != NULL)
	{
		if (*tmp && (*tmp)->flag == *flag)
		{
			ft_putstr((*tmp)->str);
			ft_putstr("\n");
			*tmp = (*tmp)->next;
			(*flag)++;
		}
		if (!ft_strcmp(room->line, "start_room"))
			ft_putstr("##start\n");
		else if (!ft_strcmp(room->line, "end_room"))
			ft_putstr("##end\n");
		ft_putstr(room->name);
		ft_putstr(" ");
		ft_putnbr(room->x);
		ft_putstr(" ");
		ft_putnbr(room->y);
		ft_putstr("\n");
		*flag = ((!ft_strcmp(room->line, "start_room") ||
			!ft_strcmp(room->line, "end_room")) ? *flag + 2 : *flag + 1);
		room = room->next;
	}
}

void			print_link(t_command **tmp, t_link *link, int *flag)
{
	while (link != NULL)
	{
		if (*tmp && (*tmp)->flag == *flag)
		{
			ft_putstr((*tmp)->str);
			ft_putstr("\n");
			*tmp = (*tmp)->next;
			(*flag)++;
		}
		ft_putstr(link->x);
		ft_putstr("-");
		ft_putstr(link->y);
		ft_putstr("\n");
		link = link->next;
		(*flag)++;
	}
	ft_putstr("\n");
}

void			print_valid_stack(t_lem_in *lem)
{
	int			flag;
	t_command	*tmp;

	flag = 1;
	tmp = lem->command;
	print_ant(&tmp, lem->ant, &flag);
	print_room(&tmp, lem->room, &flag);
	print_link(&tmp, lem->link, &flag);
}
