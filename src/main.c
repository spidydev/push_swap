/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:48:31 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/29 15:15:59 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(0);
	stack_a = *stack_init(&stack_a, argv, argc);
	if (!stack_a)
	{
		printf("Error\n"); //TODO libft+printf
		exit(1);
	}
	push_swap(&stack_a, &stack_b); //TODO
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
