/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:48:31 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/28 13:39:19 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack) //TESTER
{
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
}

void	print_visual_stacks(t_stack *stack_a, t_stack *stack_b) //TESTER
{
	printf("A: ");
	print_stack(stack_a);
	printf("\n");
	printf("B: ");
	print_stack(stack_b);
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		printf("Error\n"); //TODO libft+printf
		exit(1);
	}
	stack_a = *stack_init(&stack_a, argv, argc);
	if (!stack_a)
	{
		printf("Error\n"); //TODO libft+printf
		exit(1);
	}
	//TEST
	print_visual_stacks(stack_a, stack_b);
	printf("\nStack length is: %d\n", stack_len(&stack_a));
	if (is_sorted(&stack_a))
		printf("\nIs sorted!\n");
	else
		printf("\nNot sorted!\n");
	/*
	pb(&stack_b, &stack_a);
	pb(&stack_b, &stack_a);
	pb(&stack_b, &stack_a);
	print_visual_stacks(stack_a, stack_b);
	rra(&stack_a);
	rrb(&stack_b);
	print_visual_stacks(stack_a, stack_b);
	rrr(&stack_a, &stack_b);
	print_visual_stacks(stack_a, stack_b);*/
	printf("\nPROGRAM OUTPUT:\n");
	push_swap(&stack_a, &stack_b); //TODO
	printf("\n--STACKS--\n");
	print_visual_stacks(stack_a, stack_b);
	t_stack *tmpa = stack_a;
	t_stack *tmpb = stack_b;
	printf("\nSTACK A POSITIONS + INDEX\n");
	while (tmpa)
	{
		printf("%d (idx %d) node current position is: %d.\n", tmpa->value, tmpa->index, tmpa->current_pos);
		tmpa = tmpa->next;
	}
	printf("\nSTACK B POSITIONS + INDEX\n");
	while (tmpb)
	{
		printf("%d (idx %d) node current position is: %d.\n", tmpb->value, tmpb->index, tmpb->current_pos);
		tmpb = tmpb->next;
	}
	tmpa = stack_a;
	tmpb = stack_b;
	printf("\nSTACK B TARGET POS\n");
	while (tmpb)
	{
		printf("%d node target position in A is: %d.\n", tmpb->value, tmpb->target_pos);
		tmpb = tmpb->next;
	}
	if (is_sorted(&stack_a))
		printf("\nIs sorted!\n");
	else
		printf("\nNot sorted!\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
