/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:01:56 by adias-do          #+#    #+#             */
/*   Updated: 2025/02/06 18:24:00 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate(t_stack **stack, int j, int mov)
{
	t_stack	*first;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	lstadd_back(stack, first);
	if (j == 0)
	{
		if (mov == 0)
			write(1, "ra\n", 3);
		else if (mov == 1)
			write(1, "rb\n", 3);
		else
			write(1, "rr\n", 3);
	}
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, int j, int mov)
{
	ft_rotate(stack_a, 1, mov);
	ft_rotate(stack_b, 1, mov);
	if (j == 0)
	{
		if (mov == 2)
			write(1, "rr\n", 3);
	}
}
