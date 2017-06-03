/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_is_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:02:24 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 16:02:25 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_comment(char *str)
{
	return ((ft_strstr(str, "#") && !ft_strstr(str, "##")) ? 1 : 0);
}

int			is_room(char *str)
{
	char	**a;

	a = ft_strsplit(str, ' ');
	if (count_list(a) == 3 && ft_isdigit(*a[1]) == 1 && ft_isdigit(*a[2]) == 1)
	{
		free_char(a);
		return (1);
	}
	else
		free_char(a);
	return (0);
}

int			is_link(char *str)
{
	return (ft_strrchr(str, '-') != NULL ? 1 : 0);
}

void		find_ant(char *str, t_lem_in **lem, int flag)
{
	char	**arr;

	arr = ft_strsplit(str, ' ');
	if (is_comment(str) == 0)
	{
		if (ft_strstr(str, "##"))
			add_command(lem, str, flag);
		else if ((count_list(arr) > 1) || ft_isdigit(*str) == 0 ||
			ft_atoi(str) <= 0)
			(*lem)->error = 1;
		else
		{
			(*lem)->ant.nb = ft_atoi(str);
			(*lem)->ant.end = 1;
		}
	}
	free_char(arr);
}

void		find_room(t_lem_in **lem, char *str)
{
	char	**a;

	a = ft_strsplit(str, ' ');
	if ((*lem)->room_start == 2)
		add_str(lem, a, "start_room");
	else if ((*lem)->room_end == 2)
		add_str(lem, a, "end_room");
	else
		add_str(lem, a, "room");
}
