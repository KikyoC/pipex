# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 09:19:46 by togauthi          #+#    #+#              #
#    Updated: 2024/11/04 14:38:55 by togauthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isalnum.c \
ft_isprint.c \
ft_memset.c \
ft_strlcpy.c \
ft_strrchr.c \
ft_atoi.c \
ft_isalpha.c \
ft_memchr.c \
ft_strchr.c \
ft_strlen.c \
ft_tolower.c \
ft_bzero.c \
ft_isascii.c \
ft_memcpy.c \
ft_strdup.c \
ft_strncmp.c \
ft_toupper.c \
ft_memcmp.c \
ft_calloc.c \
ft_isdigit.c \
ft_memmove.c \
ft_strlcat.c \
ft_strnstr.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \

B_SRCS = ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c \

OBJS = ${SRCS:.c=.o}
B_OBJS = ${B_SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar -rc $(NAME) $^

bonus: $(OBJS) $(B_OBJS)
	@ar rc $(NAME) $(OBJS) $(B_OBJS)

clean:
	@rm -f ${OBJS} $(B_OBJS)

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
