/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:42:46 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/21 11:54:53 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*malloc_copy(size_t end, size_t start, char const *s1)
{
	char	*dest;

	if (end - start + 2 > 0)
	{
		dest = (char *)malloc(sizeof(char) * (end - start + 2));
		if (dest == NULL)
			return (NULL);
		ft_strlcpy(dest, &s1[start], end - start + 2);
	}
	else
	{
		dest = (char *)malloc(sizeof(char) * (sizeof(char)));
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*dest;

	if ((set == NULL && s1 != NULL) || *s1 == '\0')
		return (ft_strdup(s1));
	if (s1 == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) != NULL && s1[start])
		start++;
	while (ft_strchr(set, s1[end]) != NULL && end > start)
		end--;
	dest = malloc_copy(end, start, s1);
	return (dest);
}
