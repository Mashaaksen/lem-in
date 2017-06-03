/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:00:31 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 16:00:33 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			valid(t_lem_in *lem)
{
	if (lem->ant.end != 1 || lem->link_end != 1 || lem->room_end != 1
		|| lem->room_start != 1)
		error();
}

void			determine(char *str, t_lem_in **lem, int flag)
{
	if (!ft_strcmp(str, "##start"))
		(*lem)->room_start = 2;
	else if (!ft_strcmp(str, "##end"))
		(*lem)->room_end = 2;
	else if (is_room(str) == 1)
		find_room(lem, str);
	else if (is_link(str) == 1)
		add_link(lem, ft_strsplit(str, '-'), NULL, NULL);
	else if (is_comment(str) == 1)
		;
	else if (ft_strstr(str, "##"))
		add_command(lem, str, flag);
	else
		(*lem)->error = 1;
}

void			sep(t_lem_in **lem, char *str, int flag)
{
	if ((*lem)->ant.end == 0)
		find_ant(str, lem, flag);
	else
		determine(str, lem, flag);
}

void			read_valid(int flag, t_lem_in *lem)
{
	while ((get_next_line(0, &lem->str)) != 0)
	{
		is_comment(lem->str) == 0 ? flag++ : 0;
		if (((!ft_strcmp(lem->str, "##start") || !ft_strcmp(lem->str, "##end"))
	&& lem->room_end == 1 && lem->room_start == 1) || ((lem->room_start == 2 ||
	lem->room_end == 2) && is_room(lem->str) != 1) || ((lem->room_start != 1 ||
	lem->room_end != 1) && is_link(lem->str) == 1) || (lem->link_end == 1 &&
	is_room(lem->str) == 1) || lem->error == 1 || *lem->str == 'L')
		{
			valid(lem);
			break ;
		}
		else
			sep(&lem, lem->str, flag);
		free(lem->str);
	}
	valid(lem);
	valid_way(lem->room, lem->link);
	print_valid_stack(lem);
	lem->min = min_way(lem->room, lem->link);
	lem->opt = opt_way(lem->min, lem->room);
	lem->path = choose_pathways(lem->opt, lem->ant.nb);
	ant_in_link(lem->path->min, lem->ant.nb, lem->path->x);
}
