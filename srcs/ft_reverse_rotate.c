/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:24:11 by adias-do          #+#    #+#             */
/*   Updated: 2025/02/06 19:07:58 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse_rotate(t_stack **stack, int j, int mov)
{
	t_stack	*last;
	t_stack	*bf_last; // before the last

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	last = *stack;
	while (last->next)
	{
		bf_last = last;
		last = last->next;
	}
	bf_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (j == 0)
	{
		if (mov == 0)
			write(1, "rra\n", 4);
		else if (mov == 1)
			write(1, "rrb\n", 4);
		else
			write(1, "rrr\n", 4);
	}
}
