/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:34:08 by adias-do          #+#    #+#             */
/*   Updated: 2025/03/12 20:39:04 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	check_mov(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		ft_push(stack_b, stack_a, 1, 1);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		ft_push(stack_a, stack_b, 1, 0);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		ft_swap_a(stack_a, 1);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		ft_swap_b(stack_b, 1);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ft_ss(stack_a, stack_b, 1);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ft_rotate(stack_a, 1, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		ft_rotate(stack_b, 1, 1);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		ft_rr(stack_a, stack_b, 1, 2);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		ft_reverse_rotate(stack_a, 1, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		ft_reverse_rotate(stack_b, 1, 1);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		ft_rrr(stack_a, stack_b, 1, 2);
	else
		ft_error();
	return(line);
}

void	check_line(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while(line)
	{
		check_mov(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (!line && !check_sorted(stack_a, 0))
		write(1, "KO\n", 3);
	else // (!line && check_sorted(stack_a))
		write(1, "OK\n", 3);
}

int	checker(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	stack_a = ft_check_args(argc, argv);
	if (!stack_a)
	{
		ft_stackfree(&stack_a);
		ft_error();
	}
	check_line(&a, &b, line);
	ft_stackfree(&stack_a);
	ft_stackfree(&stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	return (checker(argc, argv));
}
