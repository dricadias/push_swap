/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:49:30 by adias-do          #+#    #+#             */
/*   Updated: 2025/03/11 18:59:39 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack, char *name)
{
	ft_printf("%s: ", name);
	while (stack)
	{
		ft_printf("%d ", stack->nbr);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = ft_check_args(argc, argv);
	//print_stack(stack_a, "antes");
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
	//print_stack(stack_a, "depois");
	ft_stackfree(&stack_a);
	return (0);
}
