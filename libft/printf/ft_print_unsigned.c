/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:38:53 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/29 17:43:30 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	udigit_count(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	size_t	n_len;
	char	*str;

	n_len = udigit_count(n);
	str = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[n_len--] = '\0';
	while (n != 0)
	{
		str[n_len] = n % 10 + '0';
		n_len--;
		n = n / 10;
	}
	return (str);
}

int	ft_printunsigned(unsigned int n)
{
	int		length;
	char	*nbr;

	length = 0;
	nbr = ft_uitoa(n);
	length = ft_printstr(nbr);
	free(nbr);
	return (length);
}
