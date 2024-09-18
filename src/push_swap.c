/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:23:15 by calbar-c          #+#    #+#             */
/*   Updated: 2024/09/18 16:43:23 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if(!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_push(t_stack **stack, t_stack *item)
{
	if (!stack || !item)
		return ;
	item->next = *stack;
	*stack = item;
}

void	pa(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	if (!src || !*src)
		return ;
	//Extraer nodo
	temp = *src;
	*src = (*src)->next;
	//Push a
	ft_push(dst, temp);	
}

void	pb(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	if (!src || !*src)
		return ;
	//Extraer nodo
	temp = *src;
	*src = (*src)->next;
	//Push b
	ft_push(dst, temp);	
}

void	sa(t_stack **stack_a)
{
	t_stack	*temp;

	//Comprobar que el stack tiene más de un nodo
	//Swap
	temp = *stack_a; // Almacenamos el primer nodo
	*stack_a = (*stack_a)->next; // Movemos el segundo nodo al frente
	temp->next = (*stack_a)->next; // Actualizamos el next del (antiguo) 1er nodo
	(*stack_a)->next = temp; // El nuevo primer nodo apunta al antiguo 1er nodo
}

void	sb(t_stack **stack_b)
{
	t_stack	*temp;

	//Comprobar que el stack tiene más de un nodo
	//Swap
	temp = *stack_b; // Almacenamos el primer nodo
	*stack_b = (*stack_b)->next; // Movemos el segundo nodo al frente
	temp->next = (*stack_b)->next; // Actualizamos el next del (antiguo) 1er nodo
	(*stack_b)->next = temp; // El nuevo primer nodo apunta al antiguo 1er nodo
}

void print_stack(t_stack *stack) //TESTER
{
    while (stack)
    {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a = NULL;
	t_stack	*stack_b = NULL;
	int	i = argc - 1;

	while (i >= 1)
		ft_push(&stack_a, ft_new_node(atoi(argv[i--]))); //ft_atoi TODO
	//TESTS
	print_stack(stack_a);
	sa(&stack_a);
	write(1, "\n", 1);
	print_stack(stack_a);

	return 0;
}
