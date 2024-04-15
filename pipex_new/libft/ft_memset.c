/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:41:13 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/15 12:30:31 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*char_ptr;
	unsigned char	byte_value;

	char_ptr = (unsigned char *)b;
	byte_value = (unsigned char)c;
	while (len > 0)
	{
		*char_ptr = byte_value;
		char_ptr++;
		len--;
	}
	return (b);
}
