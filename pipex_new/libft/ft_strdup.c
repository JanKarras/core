/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:16:34 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/15 18:09:34 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(const char *src, char *dest)
{
	char	*ori_dest;

	ori_dest = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ori_dest);
}

char	*ft_strdup(char const *src)
{
	int			count;
	char const	*ori_src;
	char		*dest;

	ori_src = src;
	count = 0;
	while (*src)
	{
		count++;
		src++;
	}
	dest = (char *)malloc(sizeof(char) * (count + 1));
	if (dest == NULL)
		return (NULL);
	return (ft_strcpy(ori_src, dest));
}
