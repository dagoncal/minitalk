/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:17:50 by dagoncal          #+#    #+#             */
/*   Updated: 2023/05/30 15:34:17 by dagoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_straddc_first(char c)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*ft_straddc(char *str, char c)
{
	size_t	i;
	char	*new_str;

	if (!c)
		return (NULL);
	if (!str)
		return (ft_straddc_first(c));
	new_str = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (str[++i] != '\0')
		new_str[i] = str[i];
	free(str);
	new_str[i++] = c;
	new_str[i] = '\0';
	return (new_str);
}
