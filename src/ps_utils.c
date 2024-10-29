/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:47:47 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/29 15:47:50 by calbar-c         ###   ########.fr       */
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

void	get_index(t_stack **stack_a)
{
	t_stack	*tmp;
	int		max;
	int		len;

	len = stack_len(stack_a) - 1;
	while (len >= 0)
	{
		tmp = *stack_a;
		max = INT_MIN;
		while (tmp)
		{
			if (tmp->value > max && tmp->index == -1)
				max = tmp->value;
			tmp = tmp->next;
		}
		tmp = *stack_a;
		while (tmp)
		{
			if (tmp->value == max)
				tmp->index = len--;
			tmp = tmp->next;
		}
	}
}

bool	is_sorted(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->next && tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	find_max(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = INT_MIN;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}
