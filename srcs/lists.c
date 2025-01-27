/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:46:35 by adias-do          #+#    #+#             */
/*   Updated: 2025/01/27 15:45:45 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*lst_last(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (!stack)
		return (NULL);
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

t_stack	*lst_new(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = content;
	node->next = NULL;
	return (node);
}

void	lstadd_back(t_stack **stack, t_stack *s_new)
{
	t_stack	*last;

	if (!*stack)
		*stack = s_new;
	else
	{
		last = lst_last(*stack);
		last->next = s_new;
	}
}

void	lstadd_front(t_stack **stack, t_stack *s_new)
{
	if (stack && s_new)
	{
		s_new->next = *stack;
		*stack = s_new;
	}
}

int	lstsize(t_stack *stack)
{
	int	c;

	c = 0;
	while (stack)
	{
		stack = stack->next;
		c++;
	}
	return (c);
}

/*void	lstclear(t_stack **stack, void (*del)(void *))
{
	t_stack	*temp;

	if (!*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		ft_lstdelone(*stack, del); // teria que criar outra delone ou ajustar sem usar ela.
		*stack = temp;
	}
	*stack = NULL;
}*/  // 6 funcoes no arquivo
// caso precise dela finalizo.
