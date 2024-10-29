/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:07:55 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/29 17:43:59 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_hexa_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	ft_puthexa(unsigned int n, char format)
{
	if (n >= 16)
	{
		ft_puthexa(n / 16, format);
		ft_puthexa(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_printhexa(unsigned int n, char format)
{
	int	length;

	length = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_puthexa(n, format);
	length += ft_hexa_len(n);
	return (length);
}
