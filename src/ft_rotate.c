/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:21:07 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/10 15:40:36 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	node = *stack; // Guardamos la referencia al primer nodo
	*stack = (*stack)->next; // Colocamos el 2o nodo como primero
	last = *stack; // Guardamos referencia para iterar
	while (last->next) // Iteramos con la referencia
		last = last->next;
	last->next = node; // Apuntamos con el ultimo nodo al nodo que guarda el antiguo primer nodo
	node->next = NULL; // Apuntamos con el antiguo primer nodo a NULL
}

void	ra(t_stack **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	ft_rotate(stack_a);
	printf("ra\n"); //FT_ 
}

void	rb(t_stack **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;
	ft_rotate(stack_b);
	printf("rb\n"); //FT_ 
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	printf("rr\n"); //FT_ 
}
