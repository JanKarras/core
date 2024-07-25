/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:57:40 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/20 18:01:25 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	dst_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	if (dst_ptr > src_ptr && dst_ptr + n > src_ptr)
	{
		while (n > 0)
		{
			n--;
			dst_ptr[n] = src_ptr[n];
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
