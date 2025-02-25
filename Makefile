# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 16:45:05 by adias-do          #+#    #+#              #
#    Updated: 2025/02/21 18:26:37 by adias-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
# AR = ar rcs
LIBFTDIR = libft
RM = rm -rf
SRCS = srcs/list_utils.c \
	srcs/check_args.c \
	srcs/push_swap.c \
	srcs/list_utils_2.c \
	srcs/ft_swap.c \
	srcs/ft_rotate.c \
	srcs/ft_push.c \
	srcs/ft_reverse_rotate.c \
	srcs/check_sorted.c \
	srcs/sort_three.c \
	srcs/sort_five.c \
	srcs/algorithm.c
OBJS = $(SRCS:.c=.o)

INCLUDE = -L ./libft -lft

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@make -s -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ${INCLUDE}

all: $(NAME)

#%.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make -s -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -s -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
