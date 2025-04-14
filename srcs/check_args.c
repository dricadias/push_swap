/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:57:35 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/14 15:58:26 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// if 1 argv (2 argc)
// put in stack a
t_stack	*ft_split_args(char **argv)
{
	int				i;
	int				c;
	char			**splt;
	t_stack			*stack_a;

	i = -1;
	splt = ft_split(argv[1], 32);
	if (!splt)
		ft_error(NULL, NULL);
	stack_a = NULL;
	while (splt[++i])
	{
		if (!is_valid_number(splt[i]))
			ft_error(&stack_a, splt);
		c = ft_atoi_checker(splt[i], &stack_a, splt);
		if (if_equals(stack_a, c))
		{
			ft_error(&stack_a, splt);
		}
		lstadd_back(&stack_a, lst_new(c));
	}
	ft_freestr (splt);
	free (splt);
	return (stack_a);
}

// check all args
// put in stack a
t_stack	*ft_check_args(int argc, char **argv)
{
	int			i;
	int			c;
	t_stack		*stack_a;

	i = 1;
	stack_a = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
		stack_a = ft_split_args(argv);
	else
	{
		while (i < argc)
		{
			if (!is_valid_number(argv[i]))
				ft_error(&stack_a, NULL);
			c = ft_atoi_checker(argv[i], &stack_a, NULL);
			if (if_equals(stack_a, c))
				ft_error(&stack_a, NULL);
			lstadd_back(&stack_a, lst_new(c));
			i++;
		}
	}
	return (stack_a);
}

int	ft_atoi_checker(char *str, t_stack **stack, char **splt)
{
	int				sign;
	long long		res;

	res = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		res = res * 10 + *str - '0';
		str++;
	}
	if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
		ft_error(stack, splt);
	return (res * sign);
}

// check same numbers
int	if_equals(t_stack *stack, int nb)
{
	while (stack)
	{
		if (stack->nbr == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}
