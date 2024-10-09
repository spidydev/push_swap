/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:04:19 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/09 19:23:44 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*node;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		node = *stack;
		free(node);
		*stack = (*stack)->next;
	}
	*stack = NULL;
}

void	free_and_exit(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || (*stack_a))
		free_stack(stack_a);
	if (!stack_b || (*stack_b))
		free_stack(stack_b);
	printf("Error\n"); //ft_printf
	exit(1);
}
