/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:43:00 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/20 18:01:32 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <unistd.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	if (dst == NULL && src == NULL)
		return (dst);
	dest_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	while (n > 0)
	{
		*dest_ptr = *src_ptr;
		dest_ptr++;
		src_ptr++;
		n--;
	}
	return (dst);
}
