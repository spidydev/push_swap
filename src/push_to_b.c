/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:52:44 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/18 13:14:21 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	len;
	int	pushed;

	len = stack_len(stack_a);
	pushed = 0;
	while (len > 3 && pushed < len / 2)
	{
		if ((*stack_a)->index > len / 2)
			ra(stack_a);
		else
		{
			pb(stack_b, stack_a);
			pushed++;
			len--;
		}
	}
	while (len > 3)
	{
		pb(stack_b, stack_a);
		len--;
	}
}
