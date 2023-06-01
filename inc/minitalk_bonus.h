/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:18:07 by dagoncal          #+#    #+#             */
/*   Updated: 2023/05/29 22:33:52 by dagoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUSH
# define MINITALK_BONUSH

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);

void	ft_putstr(char *str);
void	ft_putnbr(int n);

char	*ft_straddc_first(char c);
char	*ft_straddc(char *str, char c);
char	*ft_strdup(const char *str);

int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);

#endif
