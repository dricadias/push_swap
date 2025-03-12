/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:34:08 by adias-do          #+#    #+#             */
/*   Updated: 2025/03/12 17:00:08 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	ft_check_mov(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(line, "pa", 2) == 0)
		ft_push(stack_b, stack_a, 1, 1);
	else if (ft_strncmp(line, "pb", 2) == 0)
		ft_push(stack_a, stack_b, 1, 0);
	else if (ft_strncmp(line, "sa", 2) == 0)
		ft_swap_a(stack_a, 1);
	else if (ft_strncmp(line, "sb", 2) == 0)
		ft_swap_b(stack_b, 1);
	else if (ft_strncmp(line, "ss", 2) == 0)
		ft_ss(stack_a, stack_b, 1);
	else if (ft_strncmp(line, "ra", 2) == 0)
		ft_rotate(stack_a, 1, 0);
	else if (ft_strncmp(line, "rb", 2) == 0)
		ft_rotate(stack_b, 1, 1);
	else if (ft_strncmp(line, "rr", 2) == 0)
		ft_rr(stack_a, stack_b, 1, 2);
	else if (ft_strncmp(line, "rra", 3) == 0)
		ft_reverse_rotate(stack_a, 1, 0);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		ft_reverse_rotate(stack_b, 1, 1);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		ft_rrr(stack_a, stack_b, 1, 2);
	else
		ft_error();
	return();
}

int	checker(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b = NULL;
	char		*line;

	stack_a = ft_check_args(argc, argv);
	if (!check_sorted(stack_a, 0))
	{
		ft_error();
	}
	line = get_next_line(0);
	ft_check_mov(line, &stack_a, &stack_b);
	ft_stackfree(&stack_a);
	return (0);
}
