/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:49:30 by adias-do          #+#    #+#             */
/*   Updated: 2025/01/24 11:54:09 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_check_args(argc, argv);
	ft_stackfree(&a);
	return (0);
}*/

#include <stdio.h>

void print_stack(t_stack *stack, char *name)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%d ", stack->nbr);
        stack = stack->next;
    }
    printf("\n");
}
int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b = NULL;
    // Criando a pilha a partir dos argumentos
    a = ft_check_args(argc, argv);
    if (!a)
    {
        printf("Erro ao criar a pilha\n");
        return (1);
    }
    printf("Pilha inicial:\n");
    print_stack(a, "A");
    // Testando operações básicas do Push Swap
    printf("\nExecutando SA (swap A)...\n");
    ft_swap_a(&a, 0);
    print_stack(a, "A");
    printf("\nExecutando PB (push B)...\n");
    ft_push(&a, &b, 0, 1);
    print_stack(a, "A");
    print_stack(b, "B");
    printf("\nExecutando PB (push B) novamente...\n");
    ft_push(&a, &b, 0, 1);
    print_stack(a, "A");
    print_stack(b, "B");
    printf("\nExecutando RA (rotate A)...\n");
    ft_rotate(&a, 0, 0);
    print_stack(a, "A");
    printf("\nExecutando RB (rotate B)...\n");
    ft_rotate(&b, 0, 1);
    print_stack(b, "B");
    printf("\nExecutando RR (rotate A e B juntos)...\n");
    ft_rr(&a, &b, 0, 2);
    print_stack(a, "A");
    print_stack(b, "B");
    printf("\nExecutando RRA (reverse rotate A)...\n");
    ft_reverse_rotate(&a, 0, 0);
    print_stack(a, "A");
    printf("\nExecutando RRB (reverse rotate B)...\n");
    ft_reverse_rotate(&b, 0, 1);
    print_stack(b, "B");
    printf("\nExecutando RRR (reverse rotate A e B juntos)...\n");
    ft_rrr(&a, &b, 0, 2);
    print_stack(a, "A");
    print_stack(b, "B");
    printf("\nExecutando PA (push A)...\n");
    ft_push(&b, &a, 0, 0);
    print_stack(a, "A");
    print_stack(b, "B");
    // Liberando memória (se necessário)
    ft_stackfree(&a);
    ft_stackfree(&b);
    return 0;
}
