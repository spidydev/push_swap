/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:34:40 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/29 17:22:10 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit_count(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	n_len;
	char	*str;
	long	num;

	n_len = digit_count(n);
	num = n;
	str = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	if (num == 0)
		str[0] = '0';
	str[n_len--] = '\0';
	while (num)
	{
		str[n_len] = num % 10 + '0';
		n_len--;
		num = num / 10;
	}
	return (str);
}
