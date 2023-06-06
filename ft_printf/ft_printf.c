/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:23:39 by dagoncal          #+#    #+#             */
/*   Updated: 2023/02/21 12:45:58 by dagoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_format(va_list argp, char format)
{
	size_t	length;

	length = 0;
	if (format == 'c')
		length = ft_putchar(va_arg(argp, int));
	else if (format == 's')
		length = ft_putstr(va_arg(argp, char *));
	else if (format == '%')
		length = ft_putchar('%');
	else if (format == 'i' || format == 'd')
		length = ft_putnbr(va_arg(argp, int));
	else if (format == 'u')
		length = ft_putunsigned(va_arg(argp, unsigned int));
	else if (format == 'x' || format == 'X')
		length = ft_puthex(va_arg(argp, unsigned int), format);
	else if (format == 'p')
		length = ft_putptr(va_arg(argp, void *));
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	argp;
	size_t	i;
	size_t	length;

	i = 0;
	length = 0;
	if (!str)
		return (-1);
	va_start(argp, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			length += ft_printf_format(argp, str[(i++) + 1]);
		else
			length += ft_putchar(str[i]);
		i++;
	}
	va_end(argp);
	return (length);
}
