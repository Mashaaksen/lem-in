/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:21:07 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/26 15:21:09 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define RED   "\x1B[31m"
# define BLU   "\x1B[34m"
# define END   "\x1B[0m"

# include "libft/libft.h"
# include <stdio.h>

typedef	struct				s_command
{
	char					*str;
	int						flag;
	struct s_command		*next;
}							t_command;

typedef	struct				s_ant
{
	int						nb;
	int						end;
}							t_ant;

typedef	struct				s_room
{
	char					*line;
	char					*name;
	int						x;
	int						y;
	struct s_room			*next;
}							t_room;

typedef	struct				s_link
{
	char					*x;
	char					*y;
	struct s_link			*next;
}							t_link;

typedef	struct				s_way
{
	char					*room;
	struct s_way			*next;
}							t_way;

typedef	struct				s_way_min
{
	t_way					*min;
	int						x;
	struct s_way_min		*next;
}							t_way_min;

typedef	struct				s_way_opt
{
	t_way_min				*min;
	int						x;
	struct s_way_opt		*next;
}							t_way_opt;

typedef	struct				s_passed_room
{
	int						digit;
	int						status;
	struct s_passed_room	*next;
}							t_passed_room;

typedef	struct				s_passed
{
	t_passed_room			*number;
	struct s_passed			*next;
}							t_passed;

typedef	struct				s_x
{
	t_passed_room			*number;
	t_way					*path;
	int						len;
	struct s_x				*next;
}							t_x;

typedef	struct				s_end
{
	char					*str;
	t_link					*link;
}							t_end;

typedef	struct				s_lem_in
{
	t_way_opt				*opt;
	t_way_opt				*path;
	t_way_min				*min;
	t_command				*command;
	t_ant					ant;
	t_room					*room;
	t_link					*link;
	char					*str;
	int						room_start;
	int						room_end;
	int						error;
	int						link_end;
}							t_lem_in;

void						read_valid(int flag, t_lem_in *lem);
int							count_list(char	**arr);
void						add_str(t_lem_in **lem, char **a, char *line);
void						add_link(t_lem_in **lem, char **a, t_link *tmp,
								t_link *head);
void						error(void);
t_lem_in					*create_lem(void);
void						check_room(char **a, t_lem_in **lem, char *line);
void						valid(t_lem_in *lem);
void						check_link(t_lem_in **lem, t_room *room,
								char *x, char *y);
void						valid_way(t_room *room, t_link *link);
t_way						*add_way(t_way *way, char *str);
void						free_last(t_way **way);
char						*find_next(t_link *link, t_way *way, int i);
int							find_in_way(t_way *way, t_link *link, int x,
								int y);
int							sum_room(char *next, t_link *link);
void						find_start_end(t_room *room, char **start,
								char **end);
void						print_valid_stack(t_lem_in *lem);
t_way_min					*min_way(t_room *room, t_link *link);
t_way_opt					*opt_way(t_way_min *all_pathways, t_room *room);
t_way						*dup_way(t_way *way, int len);
t_way_opt					*choose_pathways(t_way_opt *opt, int ant);
void						ant_in_link(t_way_min *pathway, int ant, int k);
void						print_x(t_x *x);
void						add_command(t_lem_in **lem, char *str, int flag);
void						free_way_min(t_way_min **way);
void						free_char(char **arr);
t_way_min					*dup_pathways(t_way_min *all_pathways);
int							is_comment(char *str);
int							is_room(char *str);
int							is_link(char *str);
void						find_ant(char *str, t_lem_in **lem, int flag);
void						find_room(t_lem_in **lem, char *str);
void						add_opt_min(t_way_min *min, t_way_opt **opt,
								t_room *room, int i);
void						add_pathways(t_way_min **head,
								t_way_min *all_pathways);
void						free_ant_s(t_passed **ant_s);
void						free_x(t_x **x);
void						create_passed_room(t_passed **ant_s);
void						add_passed(t_passed_room **number, int nb);
void						create_passed(int x, t_passed **ant_s, int ant);
void						create_passed_ant(int digit, t_passed **ant_s,
								int ant, int x);
void						create_x(t_way_min *path, t_passed *ant, t_x **x);
void						add_x(t_passed *ant, t_way_min *path, t_x **x);
int							last_el(char *room, t_way *last, char *start,
								char *end);

#endif
