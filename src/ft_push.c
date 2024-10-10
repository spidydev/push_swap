/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:04:31 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/10 12:45:14 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_push(t_stack **dst, t_stack **src)
{
	t_stack	*node;

	if (!src || !*src)
		return ;
	node = *src; // Guardamos el primer nodo de src en una temporal
	*src = (*src)->next; // Cambiamos el primer nodo de src al segundo
	if (dst)
		node->next = *dst; // Colocamos el nodo temporal al principio de dst
	*dst = node; // Cambiamos la referencia del primer nodo dst al nodo temporal
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b || !*stack_b)
		return ;
	ft_push(stack_a, stack_b);
	printf("pa\n"); // FT_ TODO
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{	
	if (!stack_a || !*stack_a)
		return ;
	ft_push(stack_b, stack_a);
	printf("pb\n"); // FT_ TODO
}
