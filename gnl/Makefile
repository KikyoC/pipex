# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 13:32:47 by togauthi          #+#    #+#              #
#    Updated: 2024/11/19 11:44:52 by togauthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
SRCS = get_next_line.c \
	get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

%.o: %.c
	@$(CC) -fPIE $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar -rc $(NAME) $^

clean:
	@rm -f ${OBJS} $(B_OBJS)

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re