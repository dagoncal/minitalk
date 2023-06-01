/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:18:14 by dagoncal          #+#    #+#             */
/*   Updated: 2023/05/30 15:39:06 by dagoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strdup(const char *str)
{
	char	*new_str;
	size_t	i;

	if (!str)
		return (NULL);
	new_str = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = -1;
	while (str[++i] != '\0')
		new_str[i] = str[i];
	new_str[i] = '\0';
	return (new_str);
}
