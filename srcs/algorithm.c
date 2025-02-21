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

// 1 for rotate (if nbr is in the top half of stack)
// 0 for reverse rotate (if its in the bottom half of stack)
int	cheapest_rotate(t_stack *stack, int nbr)
{
	int	size;
	int	index;

	size = lstsize(stack);
	index = ft_index(stack, nbr);
	if (index <= size / 2)
		return (0);
	else
		return (1);
}