/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:55:19 by calbar-c          #+#    #+#             */
/*   Updated: 2023/09/22 12:55:23 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;

	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	if (src < dst)
		while (n--)
			ds[n] = sr[n];
	else
		while (n--)
			*ds++ = *sr++;
	return (dst);
}
