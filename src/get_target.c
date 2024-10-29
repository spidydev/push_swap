/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:48:56 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/29 13:25:11 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_current_pos(t_stack **stack)
{
	int	i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->current_pos = i++;
		tmp = tmp->next;
	}
}

void	clear_target(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->target_pos = -1;
		tmp = tmp->next;
	}
}

int	find_min_idx(t_stack **stack)
{
	int	min;
	int	pos;
	t_stack	*tmp;

	min = INT_MAX;
	pos = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	tmp = *stack;
	while(tmp)
	{
		if (tmp->index == min)
			pos = tmp->current_pos;
		tmp = tmp->next;
	}
	return (pos);
}

void	get_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int	p_hold;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	p_hold = INT_MAX;
	get_current_pos(stack_a);
	get_current_pos(stack_b);
	while(tmp_b)
	{
		tmp_a = *stack_a;
		p_hold = INT_MAX;
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
