/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:40:36 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/09 19:41:05 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_new_node(int value)
{
        t_stack *new;

        new = (t_stack *)malloc(sizeof(t_stack));
        if(!new)
                return (NULL);
        new->value = value;
        new->next = NULL;
        return (new);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new;
}

void	free_substr(char **substr)
{
	size_t	i;

	i = 0;
	if (!substr)
		return ;
	while (substr[i])
		free(substr[i++]);
	free(substr);
}

t_stack	**stack_init(t_stack **stack_a, char **argv, int argc)
{
	char	**substring;
	int	nbr;
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		substring = ft_split(argv[i], 32); //TOLINK
		j = 0;
		while (substring[j])
		{
			if (!ft_is_number(substring[j]) || !ft_is_int(substring[j]))
				free_and_exit(stack_a, NULL);
			nbr = ft_atoi(substring[j]); //TOLINK
			if (check_duplicate(stack_a, nbr))
				free_and_exit(stack_a, NULL);
			stack_add_back(stack_a, ft_new_node(nbr));
			j++;
		}
		free_substr(substring);
		i++;
	}
	return (stack_a);
}
