/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:40:12 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 17:40:14 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				check_name(char *str, t_room *room)
{
	t_room		*tmp;
	int			flag;

	flag = 0;
	tmp = room;
	while (tmp != NULL)
	{
		if (!ft_strcmp(str, tmp->name))
			flag++;
		tmp = tmp->next;
	}
	return (flag > 1 ? 1 : 0);
}

int				check_coord1(char *str1, char *str2)
{
	while (*str1 != '\0')
	{
		if (ft_isdigit(*str1) == 0)
			return (1);
		str1++;
	}
	while (*str2 != '\0')
	{
		if (ft_isdigit(*str2) == 0)
			return (1);
		str2++;
	}
	return (0);
}

long long		ft_atoi_long(char *str)
{
	long long	n;
	long long	res;

	res = 0;
	n = 1;
	if (!(*str))
		return (0);
	while (*(char *)str == ' ' || *(char *)str == '\f' || *(char *)str == '\r'
		|| *(char *)str == '\v' || *(char *)str == '\n'
		|| *(char *)str == '\t')
		str++;
	if (*(char *)str == '-' || *(char *)str == '+')
	{
		n = (*(char *)str == '-' ? -1 : 1);
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + *(char *)str - '0';
		str++;
	}
	return (res * n);
}

int				check_coord2(int x, int y, t_room *room)
{
	t_room		*tmp;
	int			flag;

	tmp = room;
	flag = 0;
	while (tmp != NULL)
	{
		if (tmp->x == x && tmp->y == y)
			flag++;
		tmp = tmp->next;
	}
	return (flag > 1 ? 1 : 0);
}

void			check_room(char **a, t_lem_in **lem, char *line)
{
	int			flag;
	char		*str;
	long long	nb1;
	long long	nb2;

	flag = 0;
	nb1 = ft_atoi_long(a[1]);
	nb2 = ft_atoi_long(a[2]);
	(nb1 > 2147483647 || nb1 < 0 || nb2 > 2147483647 || nb2 < 0) ? flag++ : 0;
	if (check_name(a[0], (*lem)->room) != 0 || check_coord1(a[1], a[2]) != 0
		|| flag != 0 || check_coord2(ft_atoi(a[1]), ft_atoi(a[2]),
		(*lem)->room) != 0)
		(*lem)->error = 1;
	else if (!ft_strcmp(line, "start_room"))
		(*lem)->room_start = 1;
	else if (!ft_strcmp(line, "end_room"))
		(*lem)->room_end = 1;
	str = a[0];
	free(str);
	str = a[1];
	free(str);
	str = a[2];
	free(str);
	free(a);
}
