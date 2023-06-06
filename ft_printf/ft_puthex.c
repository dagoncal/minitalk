/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:14:09 by dagoncal          #+#    #+#             */
/*   Updated: 2023/02/21 12:34:15 by dagoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	ft_hexlength(unsigned int nbr)
{
	size_t	length;

	length = 0;
	if (nbr == 0)
		length++;
	while (nbr > 0)
	{
		nbr /= 16;
		length++;
	}
	return (length);
}

void	ft_printhex(unsigned int nbr, char format)
{
	if (nbr >= 16)
	{
		ft_printhex(nbr / 16, format);
		ft_printhex(nbr % 16, format);
	}
	else
	{
		if (nbr <= 9)
		{
			ft_putchar(nbr + '0');
		}
		else
		{
			if (format == 'x')
				ft_putchar(nbr - 10 + 'a');
			else
				ft_putchar(nbr - 10 + 'A');
		}
	}
}

size_t	ft_puthex(unsigned int nbr, char format)
{
	ft_printhex(nbr, format);
	return (ft_hexlength(nbr));
}
