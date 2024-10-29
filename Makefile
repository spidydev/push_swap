# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 16:01:23 by calbar-c          #+#    #+#              #
#    Updated: 2024/10/29 18:48:41 by calbar-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a

SRC = \
	src/push_swap.c src/main.c src/init.c src/validate.c src/ps_utils.c \
	src/push_to_b.c src/get_target.c src/get_cost.c src/ft_push.c \
	src/ft_swap.c src/ft_rotate.c src/ft_reverse_rotate.c \
	src/do_cheapest.c src/do_move.c src/free_stack.c src/finish_sort.c

OBJ = $(SRC:.c=.o)

CC = cc -Wall -Wextra -Werror

$(LIBFT):
	@$(MAKE) -s -C libft

$(NAME) : $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) $(LIBFT) -o $@

all: $(NAME)

clean:
	@$(MAKE) -s -C libft clean
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -s -C libft fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
