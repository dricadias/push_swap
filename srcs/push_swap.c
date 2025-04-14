/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:49:30 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/14 16:11:01 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// main function of the code, to organize the numbers
void	ft_algorithm(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	stack_b = push_stack_b(stack_a);
	sort_stack_a(stack_a, &stack_b);
	ft_rotate_to_min(stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = ft_check_args(argc, argv);
	if (!check_sorted(stack_a, 0))
	{
		if (lstsize(stack_a) == 2)
			ft_swap_a(&stack_a, 0);
		else if (lstsize(stack_a) == 3)
			sort_three(&stack_a);
		else if (lstsize(stack_a) == 4)
			sort_four(&stack_a);
		else if (lstsize(stack_a) >= 5)
			ft_algorithm(&stack_a);
	}
	ft_stackfree(&stack_a);
	return (0);
}
