/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:44:32 by adias-do          #+#    #+#             */
/*   Updated: 2025/02/05 18:11:54 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// first = *stack; --> define as first
// second = first->next; --> points to the second
// first->next = second->next; --> 1º next points to 3º
// second->next = first; --> 2º next points for 1º
void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ft_swap_a(t_stack **stack_a, int i)
{
	if (!stack_a || !*stack_a || !((*stack_a)->next))
		return ;
	ft_swap(stack_a);
	if (i == 0)
		write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack **stack_b, int i)
{
	if (!stack_b || !*stack_b || !((*stack_b)->next))
		return ;
	ft_swap(stack_b);
	if (i == 0)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (!stack_a || !*stack_a || !((*stack_a)->next)
		|| !stack_b || !*stack_b || !((*stack_b)->next))
		return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (i == 0)
		write(1, "ss\n", 3);
}
