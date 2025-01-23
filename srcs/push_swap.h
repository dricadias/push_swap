/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:46:10 by adias-do          #+#    #+#             */
/*   Updated: 2025/01/21 16:50:20 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
#	include "../libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void	ft_error(void);

#endif

