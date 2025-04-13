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
int	ft_find_stack_place(t_stack *stck, int nbr_f, int ty)
{
	int		i;
	t_stack	*temp;

	if (!stck)
		return (0);
	i = 1;
	temp = stck->next;
	if ((ty == 0 && (nbr_f < stck->nbr && nbr_f > lst_last(stck)->nbr))
		|| (ty == 1 && (nbr_f > stck->nbr && nbr_f < lst_last(stck)->nbr)))
		return (0);
	else if (nbr_f > ft_max(stck) || nbr_f < ft_min(stck))
	{
		if (ty == 0)
			return (ft_index(stck, ft_min(stck)));
		else
			return (ft_index(stck, ft_max(stck)));
	}
	while ((ty == 0 && (stck->nbr > nbr_f || temp->nbr < nbr_f))
		|| (ty == 1 && (stck->nbr < nbr_f || temp->nbr > nbr_f)))
	{
		stck = stck->next;
		temp = stck->next;
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
		if ((i < (lstsize(b) - ft_index(b, nbr_first)))
			&& ft_index(b, nbr_first))
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
