/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:57:26 by calbar-c          #+#    #+#             */
/*   Updated: 2023/09/28 15:57:28 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (NULL);
	while (is_set(s1[start], set) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(s1 + end + 1));
	while (is_set(s1[end], set) && end >= 0)
		end--;
	s2 = (char *)malloc(end - start + 2);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, &s1[start], end - start + 2);
	return (s2);
}
