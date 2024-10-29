/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:22:40 by calbar-c          #+#    #+#             */
/*   Updated: 2023/09/14 11:22:42 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;

	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	while (n--)
		*ds++ = *sr++;
	return (dst);
}
