/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:01:18 by dagoncal          #+#    #+#             */
/*   Updated: 2023/02/21 12:36:34 by dagoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_ptrlength(unsigned long long ptr)
{
	size_t	length;

	length = 0;
	while (ptr > 0)
	{
		ptr /= 16;
		length++;
	}
	return (length);
}

void	ft_printptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_printptr(ptr / 16);
		ft_printptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'a');
	}
}

size_t	ft_putptr(void *ptr)
{
	size_t				length;
	unsigned long long	ptr_ref;

	if (!ptr)
		return (write(1, "(nil)", 5));
	ptr_ref = (unsigned long long) ptr;
	length = write(1, "0x", 2);
	ft_printptr(ptr_ref);
	length += ft_ptrlength(ptr_ref);
	return (length);
}
