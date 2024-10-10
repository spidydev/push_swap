/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:42:11 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/10 16:23:36 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack *prev_last;
	t_stack *last;

	if (!*stack || !(*stack)->next)
		return ;
	prev_last = *stack;
	while (prev_last->next && prev_last->next->next)
		prev_last = prev_last->next;
	last = prev_last->next;
	prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	ft_reverse_rotate(stack_a);
	printf("rra\n"); //FT_ TODO
}

void	rrb(t_stack **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;
	ft_reverse_rotate(stack_b);
	printf("rrb\n"); //FT_ TODO
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	printf("rrr\n"); //FT_ TODO
}
