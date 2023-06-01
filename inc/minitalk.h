/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:18:07 by dagoncal          #+#    #+#             */
/*   Updated: 2023/05/30 16:34:02 by dagoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

size_t	ft_strlen(const char *str);

void	ft_putstr(char *str);
void	ft_putnbr(int n);

char	*ft_straddc_first(char c);
char	*ft_straddc(char *str, char c);
char	*ft_strdup(const char *str);

int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);

#endif
