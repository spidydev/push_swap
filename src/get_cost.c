/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:03:54 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/28 15:52:17 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		len_a;
	int		len_b;

	tmp_b = *stack_b;
	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (tmp_b)
	{
		if (tmp_b->current_pos > (len_b / 2))
			tmp_b->cost_b = (len_b - tmp_b->current_pos) * -1;
		else
			tmp_b->cost_b = tmp_b->current_pos;
		if (tmp_b->target_pos > (len_a / 2))
			tmp_b->cost_a = (len_a - tmp_b->target_pos) * -1;
		else
			tmp_b->cost_a = tmp_b->target_pos;
		tmp_b = tmp_b->next;
	}
}
