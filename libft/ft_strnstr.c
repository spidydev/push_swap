/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:40:52 by calbar-c          #+#    #+#             */
/*   Updated: 2023/09/21 14:40:53 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (ft_strlen(tofind) == 0)
		return ((char *)&str[i]);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == tofind[j] && tofind[j] && i + j < n)
			j++;
		if (tofind[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
