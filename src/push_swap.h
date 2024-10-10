/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:23:45 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/10 12:26:54 by calbar-c         ###   ########.fr       */
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

//FREE
void	free_stack(t_stack **stack);
void	free_and_exit(t_stack **stack_a, t_stack **stack_b);
#endif
