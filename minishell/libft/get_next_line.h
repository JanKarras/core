/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:35:53 by rmatthes          #+#    #+#             */
/*   Updated: 2024/03/14 13:26:28 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft.h"

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1

# endif

char	*get_next_line(int fd);
char	*ft_join(char *s1, char *s2);
char	*ft_strcpy_endl(char *dst, char *src);

#endif
