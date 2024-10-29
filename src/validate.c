/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:26:43 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/10 11:49:46 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ctype.h>

static long long int	ft_atoll(const char *str)
{
	long long int	n;
	int				sign;

	n = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
		n = n * 10 + *str++ - 48;
	return (n * sign);
}

bool	ft_is_number(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
		if (!isdigit(s[i++]))//FT_ TODO
			return (0);
	return (1);
}

bool	ft_is_int(char *s)
{
	long long int	long_nbr;

	long_nbr = 0;
	if (!s)
		return (0);
	long_nbr = ft_atoll(s);
	if (long_nbr > INT_MAX || long_nbr < INT_MIN)
		return (0);
	return (1);
}

bool	check_duplicate(t_stack **stack_a, int nbr)
{
	t_stack	*current;

	if (!stack_a || !(*stack_a))
		return (0);
	current = *stack_a;
	while (current)
	{
		if (current->value == nbr)
			return (1);
		current = current->next;
	}
	return (0);
}
