/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:14:06 by dagoncal          #+#    #+#             */
/*   Updated: 2023/02/21 11:58:26 by dagoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_length(int nbr)
{
	unsigned int	length;

	length = 0;
	if (nbr <= 0)
		length++;
	while (nbr != 0)
	{
		length++;
		nbr /= 10;
	}
	return (length);
}

static int	absolute(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static char	*ft_itoa(int nbr)
{
	unsigned int	length;
	char			*str;

	length = get_length(nbr);
	str = (char *)malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[length] = '\0';
	if (nbr < 0)
		str[0] = '-';
	else if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[--length] = absolute(nbr % 10) + 48;
		nbr /= 10;
	}
	return (str);
}

size_t	ft_putnbr(int nbr)
{
	char		*str;
	size_t		length;

	str = ft_itoa(nbr);
	length = ft_putstr(str);
	free(str);
	return (length);
}
