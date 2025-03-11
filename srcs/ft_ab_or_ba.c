/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ab_or_ba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:08:08 by adias-do          #+#    #+#             */
/*   Updated: 2025/03/11 16:08:08 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_type_ab(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*temp;

	temp = stack_a;
	i = ft_rr_or_rrr(stack_a, stack_b, stack_a->nbr, 1);
	while (temp)
	{
		if (i > ft_rr_or_rrr(stack_a, stack_b, temp->nbr, 0))
			i = ft_rr_or_rrr(stack_a, stack_b, temp->nbr, 0);
		if (i > ft_rr_or_rrr(stack_a, stack_b, temp->nbr, 1))
			i = ft_rr_or_rrr(stack_a, stack_b, temp->nbr, 1);
		if (i > ft_rra_rb_or_ra_rrb(stack_a, stack_b, temp->nbr, 2))
			i = ft_rra_rb_or_ra_rrb(stack_a, stack_b, temp->nbr, 2);
		if (i > ft_rra_rb_or_ra_rrb(stack_a, stack_b, temp->nbr, 3))
			i = ft_rra_rb_or_ra_rrb(stack_a, stack_b, temp->nbr, 3);
		temp = temp->next;
	}
	return (i);
}

int	ft_type_ba(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*temp;

	i = ft_rr_or_rrr_a(stack_a, stack_b, stack_b->nbr, 1);
	temp = stack_b;
	while (temp)
	{
		if (i > ft_rr_or_rrr_a(stack_a, stack_b, temp->nbr, 0))
			i = ft_rr_or_rrr_a(stack_a, stack_b, temp->nbr, 0);
		if (i > ft_rr_or_rrr_a(stack_a, stack_b, temp->nbr, 1))
			i = ft_rr_or_rrr_a(stack_a, stack_b, temp->nbr, 1);
		if (i > ft_rra_rb_or_ra_rrb_a(stack_a, stack_b, temp->nbr, 2))
			i = ft_rra_rb_or_ra_rrb_a(stack_a, stack_b, temp->nbr, 2);
		if (i > ft_rra_rb_or_ra_rrb_a(stack_a, stack_b, temp->nbr, 3))
			i = ft_rra_rb_or_ra_rrb_a(stack_a, stack_b, temp->nbr, 3);
		temp = temp->next;
	}
	return (i);
}