/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:00:19 by adias-do          #+#    #+#             */
/*   Updated: 2025/02/27 01:00:19 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// it determines the index where nbr_first should be based on the stack type
// type == 0 for stack A
// type == 1 for stack B
int ft_find_stack_place(t_stack *stack, int nbr_first, int type)
{
	int		i;
	t_stack	*temp;

	if (!stack)
		return (0);
	i = 1;
	temp = stack->next;
	if ((type == 0 && (nbr_first < stack->nbr && nbr_first > lst_last(stack)->nbr)) 
	|| (type == 1 && (nbr_first > stack->nbr && nbr_first < lst_last(stack)->nbr)))
		return (0);
	else if (nbr_first > ft_max(stack) || nbr_first < ft_min(stack))
	{
		if (type == 0)
			return (ft_index(stack, ft_min(stack)));
		else
			return (ft_index(stack, ft_max(stack)));
	}
	while ((type == 0 && (stack->nbr > nbr_first || temp->nbr < nbr_first)) || 
	(type == 1 && (stack->nbr < nbr_first || temp->nbr > nbr_first)))
	{
		stack = stack->next;
		temp = stack->next;
		i++;
	}
	return (i);
}

// functions (ft_rr_or_rrr and ft_rra_rb_or_ra_rrb) 
// calculate the number of rotations needed to place nbr_first 
//
// ft_rr_or_rrr:
// type == 0 for rr
// type == 1 for rrr
int	ft_rr_or_rrr(t_stack *a, t_stack *b, int nbr_first, int type)
{
	int	i;

	i = 0;
	if (type == 0)
	{
		i = ft_find_stack_place(b, nbr_first, 1);
		if (i < ft_index(a, nbr_first))
			i = ft_index(a, nbr_first);
	}
	else if (type == 1)
	{
		if (ft_find_stack_place(b, nbr_first, 1))
			i = lstsize(b) - ft_find_stack_place(b, nbr_first, 1);
		if ((i < (lstsize(a) - ft_index(a, nbr_first))) 
		&& ft_index(a, nbr_first))
			i = lstsize(a) - ft_index(a, nbr_first);
	}
	return (i);
}

// ft_rra_rb_or_ra_rrb:
// type == 2 for rra + rb.
// type == 3 for ra + rrb.
int	ft_rra_rb_or_ra_rrb(t_stack *a, t_stack *b, int nbr_first, int type)
{
	int	i;

	i = 0;
	if (type == 2)
	{
		if (ft_index(a, nbr_first))
			i = lstsize(a) - ft_index(a, nbr_first);
		i += ft_find_stack_place(b, nbr_first, 1);
	}
	else if (type == 3)
	{
		if (ft_find_stack_place(b, nbr_first, 1))
			i = lstsize(b) - ft_find_stack_place(b, nbr_first, 1);
		i += ft_index(a, nbr_first);
	}
	return (i);
}

// functions (ft_rr_or_rrr and ft_rra_rb_or_ra_rrb) 
// calculate the number of rotations needed to place nbr_first 
//
// ft_rr_or_rrr:
// type == 0 for rr
// type == 1 for rrr
int	ft_rr_or_rrr_a(t_stack *a, t_stack *b, int nbr_first, int type)
{
	int	i;

	i = 0;
	if (type == 0)
	{
		i = ft_find_stack_place(a, nbr_first, 0);
		if (i < ft_index(b, nbr_first))
			i = ft_index(b, nbr_first);
	}
	else if (type == 1)
	{
		i = 0;
		if (ft_find_stack_place(a, nbr_first, 0))
			i = lstsize(a) - ft_find_stack_place(a, nbr_first, 0);
		if ((i < (lstsize(b) - ft_index(b, nbr_first))) && ft_index(b, nbr_first))
			i = lstsize(b) - ft_index(b, nbr_first);
	}
	return (i);
}

// ft_rra_rb_or_ra_rrb:
// type == 2 for rra + rb.
// type == 3 for ra + rrb.
int	ft_rra_rb_or_ra_rrb_a(t_stack *a, t_stack *b, int nbr_first, int type)
{
	int	i;

	i = 0;
	if (type == 2)
	{
		if (ft_find_stack_place(a, nbr_first, 0))
			i = lstsize(a) - ft_find_stack_place(a, nbr_first, 0);
		i += ft_index(b, nbr_first);
	}
	else if (type == 3)
	{
		if (ft_index(b, nbr_first))
			i = lstsize(b) - ft_index(b, nbr_first);
		i += ft_find_stack_place(a, nbr_first, 0);
	}
	return (i);
}
