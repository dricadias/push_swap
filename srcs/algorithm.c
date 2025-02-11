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
	t_stack	*first_a;
	t_stack	*second_a;
	t_stack	*third_a;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ;
	second_a = first_a->next;
	third_a = second_a->next;
	if (!check_sorted(*stack_a, 0))
	{
		if (first_a < second_a)
	}
}
