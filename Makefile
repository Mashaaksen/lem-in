#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/31 15:42:03 by maksenov          #+#    #+#              #
#    Updated: 2017/05/31 15:42:03 by maksenov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

G = gcc

FLAG = -Wall -Wextra -Werror

SRC =   main.c \
        read_valid.c \
        count_list.c \
        add_in_list.c \
        error.c \
        create.c \
        valid_way.c \
        min_way.c \
        print_valid_stack.c \
        opt_way.c \
        choose_pathways.c \
        copy.c \
        print_x.c \
        check_room.c \
        check_link.c \
        free_all.c \
        find_some_rooms.c \
        what_is_it.c \
        add_opt_min.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	@$(G) $(FLAG) $(OBJ) libft/libft.a -o $(NAME)

%.o: %.c
	@$(G) $(FLAG) -c $<

clean:
	@make -C libft/ clean
	@rm -f *.o

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
