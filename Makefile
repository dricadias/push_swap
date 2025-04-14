# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 16:45:05 by adias-do          #+#    #+#              #
#    Updated: 2025/04/14 15:39:12 by adias-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFTDIR = libft
RM = rm -rf
SRCS_1 = srcs/push_swap.c
SRCS_2 = srcs/list_utils.c \
	srcs/check_args.c \
	srcs/list_utils_2.c \
	srcs/ft_swap.c \
	srcs/ft_rotate.c \
	srcs/ft_push.c \
	srcs/ft_reverse_rotate.c \
	srcs/check_sorted.c \
	srcs/sort_three.c \
	srcs/sort_four.c \
	srcs/algorithm.c \
	srcs/algorithm_utils.c \
	srcs/ft_apply_to_stack.c \
	srcs/ft_ab_or_ba.c \
	srcs/ft_error.c

BONUS_SRC = srcs/checker_bonus.c

OBJS_1 = $(SRCS_1:.c=.o)
OBJS_2 = $(SRCS_2:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

INCLUDE = -L ./libft -lft

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS_1) $(OBJS_2)
	@make -s -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS_1) $(OBJS_2) -o $(NAME) ${INCLUDE}

$(BONUS): ${OBJS_2} ${BONUS_OBJ}
	@make -s -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(OBJS_2) -o $(BONUS) ${INCLUDE}

all: $(NAME) $(BONUS)

bonus: $(BONUS)

clean:
	$(RM) $(OBJS_1) $(OBJS_2) $(BONUS_OBJ)
	@make -s -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS)
	@make -s -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
