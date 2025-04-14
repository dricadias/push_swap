/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:33:51 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/14 16:21:11 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "../libft/libft.h"
# include "push_swap.h"

int		checker(int argc, char **argv);
void	check_line(t_stack **stack_a, t_stack **stack_b);
char	*check_mov(t_stack **stack_a, t_stack **stack_b, char *line);
void	ft_error_void(void);

#endif