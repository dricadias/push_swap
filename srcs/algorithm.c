/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:16:46 by adias-do          #+#    #+#             */
/*   Updated: 2025/02/21 18:16:46 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_apply_rrarb(t_stack **a, t_stack **b, int c, int type)
{
	if (type == 2)
	{
		while ((*a)->nbr != c)
			ft_reverse_rotate(a, 0, 0);
		while (ft_find_stack_place(*b, c, 1) > 0)
			ft_rotate(b, 0, 1);
		ft_push(a, b, 0, 1);
	}
	return (-1);
}

// calculates the rotations and applies the cheapest one to stack b
void	sort_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	while (lstsize(*stack_a) > 3 && !check_sorted(*stack_a, 0))
	{
		temp = *stack_a;
		i = ft_type_ab(*stack_a, *stack_b);
		while(i >= 0)
		{
			if (i == ft_rr_or_rrr(*stack_a, *stack_b, temp->nbr, 0))
				i = ft_apply_a(stack_a, stack_b, temp->nbr, 0);
			else if (i == ft_rr_or_rrr(*stack_a, *stack_b, temp->nbr, 1))
				i = ft_apply_a(stack_a, stack_b, temp->nbr, 1);
			else if (i == ft_rra_rb_or_ra_rrb(*stack_a, *stack_b, temp->nbr, 2))
				i = ft_apply_a_rrarb_rarrb(stack_a, stack_b, temp->nbr, 2);
			else if (i == ft_rra_rb_or_ra_rrb(*stack_a, *stack_b, temp->nbr, 3))
				i = ft_apply_a_rrarb_rarrb(stack_a, stack_b, temp->nbr, 3);
			else
				temp = temp->next;
		}
	}
}

// pushes all nodes to stack_b til only three elements are left in stack_a
t_stack	*push_stack_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (lstsize(*stack_a) > 3 && !check_sorted(*stack_a, 0))
		ft_push(stack_a, &stack_b, 0, 1);
	if (lstsize(*stack_a) > 3 && !check_sorted(*stack_a, 0))
		ft_push(stack_a, &stack_b, 0, 1);
	if (lstsize(*stack_a) > 3 && !check_sorted(*stack_a, 0))
		sort_stack_b(stack_a, &stack_b);
	if (!check_sorted(*stack_a, 0))
		sort_three(stack_a);
	return (stack_b);
}

// calculates the rotations and applies the cheapest one to stack a
t_stack	**sort_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	while (*stack_b)
	{
		temp = *stack_b;
		i = ft_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_rr_or_rrr_a(*stack_a, *stack_b, temp->nbr, 0))
				i = ft_apply_b(stack_a, stack_b, temp->nbr, 0);
			else if (i == ft_rr_or_rrr_a(*stack_a, *stack_b, temp->nbr, 1))
				i = ft_apply_b(stack_a, stack_b, temp->nbr, 1);
			else if (i == ft_rra_rb_or_ra_rrb_a(*stack_a, *stack_b, temp->nbr, 2))
				i = ft_apply_b_rarrb_rrarb(stack_a, stack_b, temp->nbr, 2);
			else if (i == ft_rra_rb_or_ra_rrb_a(*stack_a, *stack_b, temp->nbr, 3))
				i = ft_apply_b_rarrb_rrarb(stack_a, stack_b, temp->nbr, 3);
			else
				temp = temp->next;
		}
	}
	return (stack_a);
}

// ensure that the smallest value is at the top of the stack_a at the end of the sort
void	ft_rotate_to_min(t_stack **stack_a)
{
	int	i;
	int	size;
	int	min_val;

	min_val = ft_min(*stack_a);
	i = ft_index(*stack_a, min_val);
	size = lstsize(*stack_a);
	while ((*stack_a)->nbr != min_val)
	{
		if (i < size - i)
			ft_rotate(stack_a, 0, 0);
		else
			ft_reverse_rotate(stack_a, 0, 0);
	}
}

// main function of the code, to organize the numbers
void	ft_algorithm(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (lstsize(*stack_a) == 2)
		ft_swap_a(stack_a, 0);
	else
	{
		stack_b = push_stack_b(stack_a);
		sort_stack_a(stack_a, &stack_b);
		ft_rotate_to_min(stack_a);
	}
}
