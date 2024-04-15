/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:15:03 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/17 16:47:03 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t sz)
{
	size_t	length;
	size_t	src_length;

	length = 0;
	src_length = ft_strlen(src);
	if (sz > 0)
	{
		while (sz > 1 && *src != '\0')
		{
			*dst = *src;
			dst++;
			src++;
			sz--;
			length++;
		}
		*dst = '\0';
	}
	if (sz == 0 || *src != '\0')
		return (src_length);
	return (length);
}
