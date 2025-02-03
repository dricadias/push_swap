/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerrors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:57:35 by adias-do          #+#    #+#             */
/*   Updated: 2025/02/03 15:38:49 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void) // talvez eu tire isso daqui
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

// caso seja 1 argv (2 argc)
t_stack	*ft_split_args(char **argv)
{
	int				i;
	int				c;
	char			**splt;
	t_stack		*stack_a;

	i = 0;
	splt = ft_split(argv[1], 32);
	stack_a = NULL;
	while (splt[i])
	{
		c = ft_atoi_checker(splt[i]);
		if (if_equals(stack_a, c))
			ft_error();
		lstadd_back(&stack_a, lst_new(c));
		i++;
	}
	free (splt);
	return (stack_a); // colocar no stack a
}

t_stack	*ft_checkargs(int argc, char **argv)
{
	int			i;
	int			c;
	t_stack	*stack_a;

	i = 1;
	stack_a = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
			stack_a = ft_split_args(argv);
	else // se argc > 2
	{
		while (i < argc)
		{
			c = ft_atoi_checker(argv[i]);
			if (if_equals(stack_a, c))
				ft_error();
			lstadd_back(&stack_a, lst_new(c));
			i++;
		}
	}
	return (stack_a); // colocar no stack a
} //tive que criar uma add_back e new pq as do libft sao outra struct

// args em numeros dentro do int max e min
int	ft_atoi_checker(char *str)
{
	int				sign;
	long long	res; // long long pra conseguir entrar no error 

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
		if (!ft_isdigit(*str)) // verificar se tem outro tipo de caracter
			ft_error();
		res = res * 10 + *str - '0';
		str++;
	}
	if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
		ft_error();
	return (res * sign);
}

// verificar numeros iguais
// muito ruim (lenta O(n^2)) fiz pra testar
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
