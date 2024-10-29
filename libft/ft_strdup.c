/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:08:40 by calbar-c          #+#    #+#             */
/*   Updated: 2023/09/25 13:08:41 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str_cpy;
	char	*ptr;

	str_cpy = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	ptr = str_cpy;
	if (!str_cpy)
		return (NULL);
	while (*str)
		*str_cpy++ = *str++;
	*str_cpy = '\0';
	return (ptr);
}
