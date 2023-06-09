/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:18:07 by dagoncal          #+#    #+#             */
/*   Updated: 2023/06/09 16:17:28 by dagoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h>
# include <ft_printf.h>

size_t	ft_strlen(const char *str);

char	*ft_straddc_first(char c);
char	*ft_straddc(char *str, char c);
char	*ft_strdup(const char *str);

int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);

#endif
