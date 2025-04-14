/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:36:28 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/14 16:05:05 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(t_stack **stack, char **splt)
{
	if (stack)
		ft_stackfree(stack);
	if (splt)
	{
		ft_freestr(splt);
		free(splt);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
