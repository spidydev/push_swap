/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:23:15 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/29 14:46:14 by calbar-c         ###   ########.fr       */
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
	int	max;
	int	len;

	len = stack_len(stack_a) - 1;
	while(len >= 0)
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
	int	max;

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

void	sort_three(t_stack **stack_a)
{
	int	max;

	max =  find_max(stack_a);
	if (max == (*stack_a)->value)
		ra(stack_a);
	else if (max == (*stack_a)->next->value)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		clear_target(stack_b);
		get_target(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);//TODO
	}
	if (!is_sorted(stack_a))
		finish_sort(stack_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = stack_len(stack_a);
	get_index(stack_a);
	if (!is_sorted(stack_a))
	{
		if (len == 2)
			sa(stack_a);
		else if (len == 3)
			sort_three(stack_a);
		else
			big_sort(stack_a, stack_b);//TODO
	}
}
