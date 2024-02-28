/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:21:33 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/24 16:15:52 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

//printf fucntions
int		ft_printf(const char *s, ...);
void	ft_putstr_p(char *s, size_t *counter);
void	ft_putchar_p(char c, size_t *counter);
void	ft_putnbr_p(int n, size_t *counter);
void	ft_putu_p(unsigned int n, size_t *counter);
void	ft_phex_p(unsigned int n, size_t *counter, const char *s);
void	ft_putvoidhex_p(void *p, size_t *counter);
#endif
