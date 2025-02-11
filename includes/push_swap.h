/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:46:10 by adias-do          #+#    #+#             */
/*   Updated: 2025/02/05 18:15:33 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int					nbr;
	struct s_stack		*next;	// next node
}	t_stack;

// error handling and add to stack a 
void		ft_error(void);
int			ft_atoi_checker(char *str);
int			if_equals(t_stack *stack, int nb);
t_stack		*ft_split_args(char **argv);
t_stack		*ft_check_args(int argc, char **argv);

// lists utils
t_stack		*lst_last(t_stack *lst);
t_stack		*lst_new(int content);
void		lstadd_back(t_stack **stack, t_stack *s_new);
void		lstadd_front(t_stack **stack, t_stack *s_new);
void		ft_stackfree(t_stack **stack);
int			lstsize(t_stack *stack);

// utils
void		ft_freestr(char **str);
int			check_sorted(t_stack *stack, int type);

// movements
	// swap
void		ft_swap(t_stack **stack);
void		ft_swap_a(t_stack **stack_a, int i);
void		ft_swap_b(t_stack **stack_b, int i);
void		ft_ss(t_stack **stack_a, t_stack **stack_b, int i);
	// push
void		ft_push(t_stack **stack_from, t_stack **stack_to, int j, int mov);
	// rotate
void		ft_rotate(t_stack **stack, int j, int mov);
void		ft_rr(t_stack **stack_a, t_stack **stack_b, int j, int mov);
	// reverse rotate
void		ft_reverse_rotate(t_stack **stack, int j, int mov);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b, int j, int mov);

#endif
