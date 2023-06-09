/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:18:07 by dagoncal          #+#    #+#             */
/*   Updated: 2023/06/06 16:35:49 by dagoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <ft_printf.h>

size_t	ft_strlen(const char *str);

char	*ft_straddc_first(char c);
char	*ft_straddc(char *str, char c);
char	*ft_strdup(const char *str);

int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);

#endif
