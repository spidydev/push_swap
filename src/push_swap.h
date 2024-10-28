/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:23:45 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/28 18:54:39 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> //?
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"


typedef struct	s_stack
{
	int	value;
	int	index;
	int	current_pos;
	int	target_pos;
	int	cost_a;
	int	cost_b;
	struct s_stack	*next;
}	t_stack;

//INIT
t_stack	*ft_new_node(int value);
void	stack_add_back(t_stack **stack_a, t_stack *new);
t_stack	**stack_init(t_stack **stack_a, char **argv, int argc);

//VALIDATE
bool	ft_is_number(char *s);
bool	ft_is_int(char *s);
bool	check_duplicate(t_stack **stack_a, int nbr);

//OPERATIONS
void	ft_push(t_stack **dst, t_stack **src);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	ft_swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//PUSH_SWAP
void	push_swap(t_stack **stack_a, t_stack **stack_b);
int	stack_len(t_stack **stack);
void	get_index(t_stack **stack_a);
bool	is_sorted(t_stack **stack_a);
int	find_max(t_stack **stack);
void	sort_three(t_stack **stack_a);
void	big_sort(t_stack **stack_a, t_stack **stack_b);
void	push_to_b(t_stack **stack_a, t_stack **stack_b);
void	get_target(t_stack **stack_a, t_stack **stack_b);
void	get_current_pos(t_stack **stack);
int	find_min_idx(t_stack **stack);
void	get_cost(t_stack **stack_a, t_stack **stack_b);
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void	push_back(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);
void	finish_sort(t_stack **stack_a);

//FREE
void	free_stack(t_stack **stack);
void	free_and_exit(t_stack **stack_a, t_stack **stack_b);
#endif
