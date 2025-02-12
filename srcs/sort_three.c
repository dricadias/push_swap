/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:44:04 by adias-do          #+#    #+#             */
/*   Updated: 2025/02/11 18:48:29 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	static t_stack	*first;
	static t_stack	*sec;
	static t_stack	*thrd;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ;
	first = *stack_a;
	sec = first->next;
	thrd = sec->next;
	if (!check_sorted(*stack_a, 0) && lstsize(*stack_a) == 3)
	{
		if (first->nbr < sec->nbr && first->nbr < thrd->nbr)
		{
			ft_reverse_rotate(stack_a, 0, 0);
			ft_swap_a(stack_a, 0);
		}
		else if (first->nbr > sec->nbr && sec->nbr > thrd->nbr)
		{
			ft_rotate(stack_a, 0, 0);
			ft_swap_a(stack_a, 0);
		}
		else
			one_move(stack_a, first, sec, thrd);
	}
}

void	one_move(t_stack **stack_a, t_stack *first, t_stack *sec, t_stack *thrd)
{
	if (first->nbr > sec->nbr && first->nbr > thrd->nbr)
		ft_rotate(stack_a, 0, 0);
	else if (first->nbr > sec->nbr && first->nbr < thrd->nbr)
		ft_swap_a(stack_a, 0);
	else
		ft_reverse_rotate(stack_a, 0, 0);
}
