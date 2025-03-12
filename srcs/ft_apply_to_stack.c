/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_to_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:10:56 by adias-do          #+#    #+#             */
/*   Updated: 2025/03/11 16:10:56 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_apply_a(t_stack **stack_a, t_stack **stack_b, int nbr_first, int type)
{
	while((*stack_a)->nbr != nbr_first && ft_find_stack_place(*stack_b, nbr_first, 1) > 0)
	{
		if (type == 0)
			ft_rr(stack_a, stack_b, 0, 2);
		else if (type == 1)
			ft_rrr(stack_a, stack_b, 0, 2);
	}
	while((*stack_a)->nbr != nbr_first)
	{
		if (type == 0 || type == 3)
			ft_rotate(stack_a, 0, 0);
		else if (type == 2 || type == 1)
			ft_reverse_rotate(stack_a, 0, 0);
	}
	while (ft_find_stack_place(*stack_b, nbr_first, 1) > 0)
	{
		if (type == 0 || type == 2)
			ft_rotate(stack_b, 0, 1);
		else if (type == 1 || type == 3)
			ft_reverse_rotate(stack_b, 0, 1);
	}
	ft_push(stack_a, stack_b, 0, 1);
	return (-1);
}

int	ft_apply_b(t_stack **stack_a, t_stack **stack_b, int nbr_first, int type)
{
	while((*stack_b)->nbr != nbr_first && ft_find_stack_place(*stack_a, nbr_first, 0) > 0)
	{
		if (type == 0)
			ft_rr(stack_a, stack_b, 0, 2);
		else if (type == 1)
			ft_rrr(stack_a, stack_b, 0, 2);
	}
	while(((*stack_b)->nbr) != nbr_first)
	{
		if (type == 0 || type == 2)
			ft_rotate(stack_b, 0, 1);
		else if (type == 1 || type == 3)
			ft_reverse_rotate(stack_b, 0, 1);
	}
	while (ft_find_stack_place(*stack_a, nbr_first, 0) > 0)
	{
		if (type == 0 || type == 2)
			ft_rotate(stack_a, 0, 0);
		else if (type == 1 || type == 3)
			ft_reverse_rotate(stack_a, 0, 0);
	}
	ft_push(stack_b, stack_a, 0, 0);
	return (-1);
}

int	ft_apply_a_rrarb_rarrb(t_stack **stack_a, t_stack **stack_b, int nbr_first, int type)
{
	if (type == 2)
	{
		while ((*stack_a)->nbr != nbr_first)
			ft_reverse_rotate(stack_a, 0, 0);
		while (ft_find_stack_place(*stack_b, nbr_first, 1) > 0)
			ft_rotate(stack_b, 0, 1);
		ft_push(stack_a, stack_b, 0, 1);
	}
	else if (type == 3)
	{
		while ((*stack_a)->nbr != nbr_first)
			ft_rotate(stack_a, 0, 0);
		while (ft_find_stack_place(*stack_b, nbr_first, 1) > 0)
			ft_reverse_rotate(stack_b, 0, 1);
		ft_push(stack_a, stack_b, 0, 1);
	}
	return (-1);
}

int	ft_apply_b_rarrb_rrarb(t_stack **stack_a, t_stack **stack_b, int nbr_first, int type)
{
	if (type == 2)
	{
		while (ft_find_stack_place(*stack_a, nbr_first, 0) > 0)
			ft_reverse_rotate(stack_a, 0, 0);
		while ((*stack_b)->nbr != nbr_first)
			ft_rotate(stack_b, 0, 1);
		ft_push(stack_a, stack_b, 0, 1);
	}
	else if (type == 3)
	{
		while (ft_find_stack_place(*stack_a, nbr_first, 0) > 0)
			ft_rotate(stack_a, 0, 0);
		while ((*stack_b)->nbr != nbr_first)
			ft_reverse_rotate(stack_b, 0, 1);
		ft_push(stack_a, stack_b, 0, 1);
	}
	return (-1);
}


