/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:18:54 by calbar-c          #+#    #+#             */
/*   Updated: 2023/09/21 12:18:55 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *tofind)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (ft_strlen(tofind) == 0)
		return ((char *)&str[i]);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == tofind[j] && tofind[j])
			j++;
		if (tofind[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
