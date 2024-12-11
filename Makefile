# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 09:30:05 by tom               #+#    #+#              #
#    Updated: 2024/12/11 16:47:36 by togauthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

COMMON_SRCS = mandatory/execution.c \
	mandatory/utils.c \
	mandatory/path.c \
	mandatory/pids.c \
	mandatory/pipe.c \
	mandatory/arg_fixer.c \
	

MANDATORY_SRCS = mandatory/pipex.c \
	mandatory/setup.c

BONUS_SRCS = bonus/pipex_bonus.c \
	bonus/setup_bonus.c \
	bonus/heredoc_bonus.c \

LIBFT = libft.a
GNL = gnl.a

COMMON_OBJS = $(addprefix objs/, $(COMMON_SRCS:.c=.o))
MANDATORY_OBJS = $(addprefix objs/, $(MANDATORY_SRCS:.c=.o))
BONUS_OBJS = $(addprefix objs/, $(BONUS_SRCS:.c=.o))
CFLAGS = -Wall -Werror -Wextra -g
OBJS_DIR = objs/ \
	objs/bonus/ \
	objs/mandatory/

GREEN = \e[0;32m
WHITE = \e[0;37m
AQUA = \e[0;36m
YELLOW = \e[0;33m

all: $(NAME)

$(LIBFT):
	@echo "$(YELLOW)Compiling libft... $(WHITE)[$(GREEN)2$(WHITE)/$(AQUA)3$(WHITE)]" 
	@make --no-print-directory -C libft all
	@mv libft/libft.a ./

$(GNL):
	@echo "$(YELLOW)Compiling get_next_line... $(WHITE)" 
	@make --no-print-directory -C gnl all
	@mv gnl/gnl.a ./

objs/%.o: %.c
	@cc $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJS_DIR) $(LIBFT) $(COMMON_OBJS) $(MANDATORY_OBJS)
	@echo "$(YELLOW)Compiling project... $(WHITE)[$(GREEN)3$(WHITE)/$(AQUA)3$(WHITE)]"
	@cc $(CFLAGS) -o $(NAME) $(COMMON_OBJS) $(MANDATORY_OBJS) $(LIBFT)
	@echo "$(GREEN)Done.$(WHITE)"
	
$(OBJS_DIR):
	@echo "$(YELLOW)Creating destination... $(WHITE)[$(GREEN)1$(WHITE)/$(AQUA)3$(WHITE)]"
	@mkdir -p $(OBJS_DIR)

bonus: $(OBJS_DIR) $(LIBFT) $(GNL) $(COMMON_OBJS) $(BONUS_OBJS)
	@echo "$(YELLOW)Compiling project... $(WHITE)[$(GREEN)3$(WHITE)/$(AQUA)3$(WHITE)]"
	@cc $(CFLAGS) -o $(NAME) $(COMMON_OBJS) $(BONUS_OBJS) $(GNL) $(LIBFT)
	@echo "$(GREEN)Done.$(WHITE)"
clean:
	@echo "$(YELLOW)Cleaning libft... $(WHITE)[$(GREEN)1$(WHITE)/$(AQUA)2$(WHITE)]"
	@make --no-print-directory -C libft clean
	@echo "$(YELLOW)Cleaning get_next_line... $(WHITE)[$(GREEN)2$(WHITE)/$(AQUA)3$(WHITE)]"
	@make --no-print-directory -C gnl clean
	@echo "$(YELLOW)Cleaning objects... $(WHITE)[$(GREEN)3$(WHITE)/$(AQUA)3$(WHITE)]"
	@rm -rf objs
	@echo "$(GREEN)Done.$(WHITE)"

fclean: clean
	@echo "$(YELLOW)Cleaning libft... $(WHITE)[$(GREEN)1$(WHITE)/$(AQUA)2$(WHITE)]"
	@rm -f $(LIBFT)
	@echo "$(YELLOW)Cleaning get_next_line... $(WHITE)[$(GREEN)2$(WHITE)/$(AQUA)3$(WHITE)]"
	@rm -f $(GNL)
	@echo "$(YELLOW)Cleaning result... $(WHITE)[$(GREEN)3$(WHITE)/$(AQUA)3$(WHITE)]"
	@rm -f $(NAME)
	@echo "$(GREEN)Done.$(WHITE)"

re: fclean all