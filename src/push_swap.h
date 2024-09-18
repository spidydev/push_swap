/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:23:45 by calbar-c          #+#    #+#             */
/*   Updated: 2024/09/18 14:58:41 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> //?
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>


typedef struct	s_stack
{
	int	value;
	struct s_stack	*next;
}	t_stack;

#endif
