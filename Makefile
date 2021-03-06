#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alukyane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 22:31:54 by alukyane          #+#    #+#              #
#    Updated: 2017/10/25 22:31:56 by alukyane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIB = ./libft/libft.a
LEMIN = lem-in

SOURCE_LEMIN = main.c command_handler.c check_func.c get_links.c check_path.c	\
			   make_path.c room_operations.c new_link.c

OBJS_LEMIN = $(SOURCE_LEMIN:.c=.o)

all: lib $(LEMIN) visual

visual:
	make -C ./visualization

%.o:%.c
	@gcc -Wall -Wextra -Werror -o $@ -c $<

lib:
	make -C ./libft

$(LEMIN): $(OBJS_LEMIN)
	@gcc -o $(LEMIN) $(OBJS_LEMIN) $(LIB)

clean:
	rm -f $(OBJS_LEMIN)
	make -C ./libft clean
	make -C ./visualization clean

fclean: clean
	rm -f $(LEMIN)
	make -C ./libft fclean
	make -C ./visualization fclean

re: fclean all
