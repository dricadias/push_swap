/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:46:10 by adias-do          #+#    #+#             */
/*   Updated: 2025/01/27 18:22:35 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int							nbr;
	struct s_stack	*prev;	// prev node
	struct s_stack	*next;	// next node
}	t_stack;

/*typedef struct s_stack_list
{
	struct s_stack_list *head; 	// first node
	struct s_stack_list *tail;	// last node
}	t_stack_list;*/

// error handling and add stack a 
void		ft_error(void);
int			ft_atoi_checker(char *str);
int			if_equals(t_stack *stack, int nb);
t_stack *ft_split_args(char **argv);
t_stack	*ft_checkargs(int argc, char **argv);

// lists
t_stack	*lst_last(t_stack *lst);
t_stack	*lst_new(int content);
void		lstadd_back(t_stack **stack, t_stack *s_new);
void		lstadd_front(t_stack **stack, t_stack *s_new);
int			lstsize(t_stack *stack);

#endif
