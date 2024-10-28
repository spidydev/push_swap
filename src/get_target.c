/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:48:56 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/28 13:23:11 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_current_pos(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	i = 0;
	j = 0;
	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_a)
	{
		tmp_a->current_pos = i++;
		tmp_a = tmp_a->next;
	}
	while (tmp_b)
	{
		tmp_b->current_pos = j++;
		tmp_b = tmp_b->next;
	}
}

int	find_min_idx(t_stack **stack)
{
	int	min;
	t_stack	*tmp;

	min = INT_MAX;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

void	get_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int	p_hold;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	p_hold = INT_MAX;
	get_current_pos(stack_a, stack_b);
	while(tmp_b)
	{
		tmp_a = *stack_a;
		while (tmp_a)
		{
			if (tmp_a->index > tmp_b->index && tmp_a->index < p_hold)
			{
				tmp_b->target_pos = tmp_a->current_pos;
				p_hold = tmp_a->index;
			}
			tmp_a = tmp_a->next;
		}
		if (tmp_b->target_pos == -1)
			tmp_b->target_pos = find_min_idx(stack_a);
		tmp_b = tmp_b->next;
	}
}
