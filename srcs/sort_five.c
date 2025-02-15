/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:03:02 by adias-do          #+#    #+#             */
/*   Updated: 2025/02/12 20:03:45 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_four(t_stack **stack_a)
{
	t_stack		*stack_b;
	int			index_min;

	if (!stack_a || !*stack_a || !((*stack_a)->next))
		return ;
	stack_b = NULL;
	index_min = ft_index(*stack_a, ft_min(*stack_a));
	if (index_min == 0)
		ft_push(stack_a, &stack_b, 0, 1);
	else if (index_min == 1)
		ft_swap_a(stack_a, 0);
	else if (index_min == 2)
	{
		ft_reverse_rotate(stack_a, 0, 0);
		ft_reverse_rotate(stack_a, 0, 0);
	}
	else
		ft_reverse_rotate(stack_a, 0, 0);
	if (index_min)
		ft_push(stack_a, &stack_b, 0, 1);
	sort_three(stack_a);
	ft_push(&stack_b, stack_a, 0, 0);
}

void	sort_five(t_stack **stack_a)
{
	t_stack		*stack_b;
	int			index_min;

	if (!stack_a || !*stack_a || !((*stack_a)->next))
		return ;
	stack_b = NULL;
	ft_push(stack_a, &stack_b, 0, 1);
	ft_push(stack_a, &stack_b, 0, 1);
	if (check_sorted(stack_b, 1))
		ft_swap_b(&stack_b, 0);
}
