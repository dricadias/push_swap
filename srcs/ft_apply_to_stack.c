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

int	ft_apply_a(t_stack **a, t_stack **b, int nbr_first, int type)
{
	while ((*a)->nbr != nbr_first && ft_find_stack_place(*b, nbr_first, 1) > 0)
	{
		if (type == 0)
			ft_rr(a, b, 0, 2);
		else if (type == 1)
			ft_rrr(a, b, 0, 2);
	}
	while ((*a)->nbr != nbr_first)
	{
		if (type == 0 || type == 3)
			ft_rotate(a, 0, 0);
		else if (type == 2 || type == 1)
			ft_reverse_rotate(a, 0, 0);
	}
	while (ft_find_stack_place(*b, nbr_first, 1) > 0)
	{
		if (type == 0 || type == 2)
			ft_rotate(b, 0, 1);
		else if (type == 1 || type == 3)
			ft_reverse_rotate(b, 0, 1);
	}
	ft_push(a, b, 0, 1);
	return (-1);
}

int	ft_apply_b(t_stack **a, t_stack **b, int nbr_first, int type)
{
	while ((*b)->nbr != nbr_first && ft_find_stack_place(*a, nbr_first, 0) > 0)
	{
		if (type == 0)
			ft_rr(a, b, 0, 2);
		else if (type == 1)
			ft_rrr(a, b, 0, 2);
	}
	while (((*b)->nbr) != nbr_first)
	{
		if (type == 0 || type == 2)
			ft_rotate(b, 0, 1);
		else if (type == 1 || type == 3)
			ft_reverse_rotate(b, 0, 1);
	}
	while (ft_find_stack_place(*a, nbr_first, 0) > 0)
	{
		if (type == 0 || type == 2)
			ft_rotate(a, 0, 0);
		else if (type == 1 || type == 3)
			ft_reverse_rotate(a, 0, 0);
	}
	ft_push(b, a, 0, 0);
	return (-1);
}

int	ft_apply_a_rrarb_rarrb(t_stack **a, t_stack **b, int nbr_f, int type)
{
	if (type == 2)
	{
		while ((*a)->nbr != nbr_f)
			ft_reverse_rotate(a, 0, 0);
		while (ft_find_stack_place(*b, nbr_f, 1) > 0)
			ft_rotate(b, 0, 1);
		ft_push(a, b, 0, 1);
	}
	else if (type == 3)
	{
		while ((*a)->nbr != nbr_f)
			ft_rotate(a, 0, 0);
		while (ft_find_stack_place(*b, nbr_f, 1) > 0)
			ft_reverse_rotate(b, 0, 1);
		ft_push(a, b, 0, 1);
	}
	return (-1);
}

int	ft_apply_b_rarrb_rrarb(t_stack **a, t_stack **b, int nbr_f, int type)
{
	if (type == 2)
	{
		while (ft_find_stack_place(*a, nbr_f, 0) > 0)
			ft_reverse_rotate(a, 0, 0);
		while ((*b)->nbr != nbr_f)
			ft_rotate(b, 0, 1);
		ft_push(a, b, 0, 1);
	}
	else if (type == 3)
	{
		while (ft_find_stack_place(*a, nbr_f, 0) > 0)
			ft_rotate(a, 0, 0);
		while ((*b)->nbr != nbr_f)
			ft_reverse_rotate(b, 0, 1);
		ft_push(a, b, 0, 1);
	}
	return (-1);
}
