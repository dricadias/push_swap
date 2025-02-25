/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:10:37 by adias-do          #+#    #+#             */
/*   Updated: 2025/02/10 13:04:16 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// clear stacks
void	ft_stackfree(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		(*stack)->nbr = 0;
		free(*stack);
		*stack = temp;
	}
}

// clear strings
void	ft_freestr(char **str)
{
	char	*temp;

	if (!str)
		return ;
	while (*str)
	{
		temp = *str;
		str++;
		free(temp);
	}
	*str = NULL;
}

// find index
int	ft_index(t_stack *stack, int number)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack->nbr != number)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	ft_min(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (stack->nbr < i)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}

int	ft_max(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (stack->nbr > i)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}
