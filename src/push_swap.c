/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:23:15 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/10 11:58:40 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// CAMBIAR OPERACIONES: HACER BASICAS COMPLETAS FT_PUSH,SWAP,ROTATE,REVERSE ROTATE. En las concretas solo pasar stacks e imprimir op.
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
	ft_push(dst, ft_new_node(temp->value));	
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
	ft_push(dst, ft_new_node(temp->value));	
}

void	sa(t_stack **stack_a)
{
	t_stack	*temp;

	//Comprobar que el stack tiene más de un nodo
	if (!*stack_a || !(*stack_a)->next)
		return ;
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
	if (!*stack_b || !(*stack_b)->next)
		return ;
	//Swap
	temp = *stack_b; // Almacenamos el primer nodo
	*stack_b = (*stack_b)->next; // Movemos el segundo nodo al frente
	temp->next = (*stack_b)->next; // Actualizamos el next del (antiguo) 1er nodo
	(*stack_b)->next = temp; // El nuevo primer nodo apunta al antiguo 1er nodo
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack *last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a; // Guardamos el primer nodo
	*stack_a = (*stack_a)->next; // Posicionamos el segundo nodo como primero
	last = *stack_a; // Guardamos una referencia de la lista
	while (last->next) // Recorremos la lista con su referencia
		last = last->next;
	last->next = temp; // Apuntamos con el último nodo al que antes era el primero
	temp->next = NULL; // Ahora el antiguo primer nodo es el último, por tanto apunta a NULL
}

void	rb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack *last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b; // Guardamos el primer nodo
	*stack_b = (*stack_b)->next; // Posicionamos el segundo nodo como primero
	last = *stack_b; // Guardamos una referencia de la lista
	while (last->next) // Recorremos la lista con su referencia
		last = last->next;
	last->next = temp; // Apuntamos con el último nodo al que antes era el primero
	temp->next = NULL; // Ahora el antiguo primer nodo es el último, por tanto apunta a NULL
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack **stack_a)
{
	t_stack	*pre_last;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	pre_last = *stack_a; // Guardamos la referencia del primer nodo
	while (pre_last->next && pre_last->next->next) // Recorremos la lista hasta el penúltimo nodo
		pre_last = pre_last->next;
	last = pre_last->next; // Guardamos la referencia del último nodo
	pre_last->next = NULL; // Convertimos el penúltimo nodo en el nuevo último nodo
	last->next = *stack_a; // Hacemos que el antiguo primer nodo sea el primero, haciendo que apunte al antiguo primer nodo, ahora segundo
	*stack_a = last; // Ahora el puntero a la cabeza de la lista apunta al antiguo último nodo
}

void	rrb(t_stack **stack_b)
{
	t_stack	*pre_last;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	pre_last = *stack_b; // Guardamos la referencia del primer nodo
	while (pre_last->next && pre_last->next->next) // Recorremos la lista hasta el penúltimo nodo
		pre_last = pre_last->next;
	last = pre_last->next; // Guardamos la referencia del último nodo
	pre_last->next = NULL; // Convertimos el penúltimo nodo en el nuevo último nodo
	last->next = *stack_b; // Hacemos que el antiguo primer nodo sea el primero, haciendo que apunte al antiguo primer nodo, ahora segundo
	*stack_b = last; // Ahora el puntero a la cabeza de la lista apunta al antiguo último nodo
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

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
	//push_swap(&stack_a, &stack_b); //TODO
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
