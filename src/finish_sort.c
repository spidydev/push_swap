/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:17:35 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/28 18:54:20 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_sort(t_stack **stack_a)
{
	int	len;
	int	pos;

	len = stack_len(stack_a);
	get_current_pos(stack_a);
	pos = find_min_idx(stack_a);
	if (pos > len / 2)
	{
		while (pos < len)
		{
			rra(stack_a);
			pos++;
		}
	}
	else
	{
		while (pos > 0)
		{
			ra(stack_a);
			pos--;
		}
	}
}
