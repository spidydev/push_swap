/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:18:53 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/28 18:15:42 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rrr(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while ((*cost_a) < 0 && (*cost_b) < 0)
	{
		rrr(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	do_rr(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while ((*cost_a) > 0 && (*cost_b) > 0)
	{
		rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

static void	do_ra(t_stack **stack_a, int *cost_a)
{
	while (*cost_a != 0)
	{
		if (*cost_a > 0)
		{
			ra(stack_a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			rra(stack_a);
			(*cost_a)++;
		}
	}
}

static void	do_rb(t_stack **stack_b, int *cost_b)
{
	while (*cost_b != 0)
	{
		if (*cost_b > 0)
		{
			rb(stack_b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			rrb(stack_b);
			(*cost_b)++;
		}
	}
}

void	push_back(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rrr(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rr(stack_a, stack_b, &cost_a, &cost_b);
	do_ra(stack_a, &cost_a);
	do_rb(stack_b, &cost_b);
	pa(stack_a, stack_b);
}
