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

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack; // define como primeiro
	second = first->next; // aponta pro next do primeiro (segundo)
	first->next = second->next; // o 1º next aponta pro 3º
	second->next = first; // proximo do 2º aponta pro 1º
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
