/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbar-c <calbar-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:49:33 by calbar-c          #+#    #+#             */
/*   Updated: 2024/10/29 17:43:42 by calbar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_format_output(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		length += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		length += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		length += ft_printunsigned(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		length += ft_printhexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		length += ft_printchar('%');
	return (length);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			length += ft_format_output(args, str[++i]);
		else
			length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (length);
}
