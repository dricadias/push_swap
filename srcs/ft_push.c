/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:08:35 by adias-do          #+#    #+#             */
/*   Updated: 2025/02/06 17:01:44 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push(t_stack **stack_from, t_stack **stack_to, int j, int mov)
{
	t_stack *first_from;

	if (!stack_from || !(*stack_from))
		return ;
	first_from = *stack_from;
	*stack_from = first_from->next;
	first_from->next = NULL;
	lstadd_front(stack_to, first_from);
	if (j == 0)
	{
		if (mov == 0)
			write(1, "pa\n", 3);
		else // (mov != 0)
			write(1, "pb\n", 3);
	}
}
