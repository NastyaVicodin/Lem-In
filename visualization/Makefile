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

LIB = ../libft/libft.a
VISUALIZATION = visual

SRC_VISUAL = main.c

OBJS_VISUAL = $(SRC_VISUAL:.c=.o)

all: $(VISUALIZATION)

$(LIB):
	make -C ../libft

%.o:%.c
	@gcc -Wall -Wextra -Werror -o $@ -c $<

$(VISUALIZATION): $(OBJS_VISUAL) $(LIB)
	@gcc -o $(VISUALIZATION) $(OBJS_VISUAL) $(LIB)

clean:
	rm -f $(OBJS_VISUAL)

fclean: clean
	rm -f $(VISUALIZATION)

re: fclean all
