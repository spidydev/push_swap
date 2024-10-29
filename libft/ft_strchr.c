/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:43:15 by calbar-c          #+#    #+#             */
/*   Updated: 2023/09/18 15:43:16 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
		if (*str++ == (char)c)
			return ((char *)str - 1);
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}
