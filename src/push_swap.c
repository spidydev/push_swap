/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:23:15 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/16 14:37:13 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack **stack)
{
	t_stack	*tmp;
	int		len;

	len = 0;
	tmp = *stack;
	if (!stack || !(*stack))
		return (0);
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
/*
void	get_index(t_stack **stack_a)
{
	
}

void	is_sorted(t_stack **stack_a)
{
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
}
*/
