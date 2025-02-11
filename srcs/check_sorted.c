/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:01:05 by adias-do          #+#    #+#             */
/*   Updated: 2025/02/11 16:35:45 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// check if stack a or b is sorted
int	check_sorted(t_stack *stack, int type)
{
	t_stack	*tmp;

	if (!stack || !(stack)->next)
		return (1);
	tmp = stack;
	if (type == 0)
	{
		while (tmp->next)
		{
			if (tmp->next->nbr < tmp->nbr)
				return (0);
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp->next)
		{
			if (tmp->next->nbr > tmp->nbr)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}
