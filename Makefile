# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manugonz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 19:27:57 by manugonz          #+#    #+#              #
#    Updated: 2023/06/27 19:28:19 by manugonz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf_utils.c ft_printf.c to_hexa.c set_pointer.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

so:
	$(CC) $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o ft_printf.so $(OBJ)

$(NAME): $(OBJS)
	ar -rcs $@ $(OBJS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f $(OBJS) $(BOBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
