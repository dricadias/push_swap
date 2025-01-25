/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerrors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:57:35 by adias-do          #+#    #+#             */
/*   Updated: 2025/01/23 20:12:07 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

t_stack ft_checkargs(int argc, char **argv)
{
	char	**splt;

	splt = ft_split(argv[1], 32);
	/*if (argc < 2) // nao sei se preciso disso aqui ou na main
		ft_error();*/
	if (argc == 2)
		// chamar funcao pra separar os numeros
		// e checar se tem letras etc
	else // caso seja apenas numeros
			// colocar os args na stack a
}

// args em numeros
int	ft_atoi_checker(char *str)
{
	int	res;
	int sign;

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
	while (*str >= '0' && *str <= '9')
	{
		/*if (!ft_isdigit)
			ft_error();*/
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
} // modificar depois de acordo com o que preciso
