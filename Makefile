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

SOURCE_LEMIN = main.c command_handler.c check_func.c get_links.c

OBJS_LEMIN = $(SOURCE_LEMIN:.c=.o)

all: $(LEMIN) vis

%.o:%.c
	@gcc -Wall -Wextra -Werror -o $@ -c $<

$(LIB):
	make -C ./libft

$(LEMIN): $(OBJS_LEMIN) $(LIB)
	gcc -o $(LEMIN) $(OBJS_LEMIN) $(LIB)

clean:
	rm -f $(OBJS_LEMIN)
	make -C ./libft clean

fclean: clean
	rm -f $(LEMIN)
	make -C ./libft fclean

re: fclean all
