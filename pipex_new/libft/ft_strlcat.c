/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:32:23 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/21 12:42:18 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	length;

	length = ft_strlen(dest) + ft_strlen(src);
	if (size == 0)
		return (ft_strlen(src));
	if (ft_strlen(dest) > size)
	{
		return (ft_strlen(src) + size);
	}
	while (*dest)
	{
		dest++;
		size--;
	}
	while (*src != '\0' && size > 1)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = '\0';
	return (length);
}
