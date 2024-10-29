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
	node = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = node;
	node->next = NULL;
}

void	ra(t_stack **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
