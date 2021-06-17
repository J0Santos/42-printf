# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josantos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 18:21:24 by josantos          #+#    #+#              #
#    Updated: 2021/03/31 16:58:45 by josantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
NAME =  libftprintf.a
SRCS= ft_printf.c \
	  srcs/conv_c.c \
	  srcs/conv_d_i.c \
	  srcs/conv_p.c \
	  srcs/conv_percentage.c \
	  srcs/conv_s.c \
	  srcs/conv_u.c \
	  srcs/conv_x.c \
	  srcs/get_case.c \
	  srcs/set_params.c \
	  srcs/arg_conversion.c \
	  srcs/handle_width.c \
	  srcs/arg_conversion.c \
	  srcs/handle_numbs.c \
	  srcs/conv_n.c \
	  srcs/handle_flags.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

$(NAME): ${OBJS}
	${MAKE} -C ./libft
	cp ${LIBFT} ${NAME}
	ar -rcs ${NAME} ${OBJS}

all: ${NAME}

bonus: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
	${MAKE} fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
