/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:34:47 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/20 18:16:06 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = count * size;
	if (size != 0 && i / size != count)
		return (NULL);
	else
		ptr = (void *)malloc(i);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, i);
	return (ptr);
}
