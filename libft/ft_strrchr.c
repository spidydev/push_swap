/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:36:11 by calbar-c          #+#    #+#             */
/*   Updated: 2023/09/21 11:36:13 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	while (*str)
		str++;
	if (c == '\0')
		return ((char *)str);
	while (str >= s)
		if (*str-- == (char)c)
			return ((char *)str + 1);
	return (NULL);
}
