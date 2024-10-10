/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:46:42 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/10 14:13:02 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*node;

	if (!*stack || !(*stack)->next)
		return ;
	node = *stack; // Almacenamos referencia a la cabeza (1er nodo)
	*stack = (*stack)->next; // La cabeza ahora es el siguiente nodo (2o)
	node->next = (*stack)->next; // Apuntamos con el nodo temporal a donde apunta el antiguo segundo nodo
	(*stack)->next = node; // Apuntamos con el antiguo segundo nodo al nodo temporal
}

void	sa(t_stack **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	ft_swap(stack_a);
	printf("sa\n"); //FT_ TODO
}

void	sb(t_stack **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;
	ft_swap(stack_b);
	printf("sb\n"); //FT_ TODO
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next) //depende del algoritmo?
		return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
	printf("ss\n");//FT_ TODO
}
