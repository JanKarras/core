/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:24:33 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/13 12:04:01 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*dest;
	char	*ori_dest;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = (char *)malloc((sizeof(char) * (len1 + len2 + 1)));
	if (dest == NULL)
		return (NULL);
	ori_dest = dest;
	while (*s1)
	{
		*dest = *s1;
		dest++;
		s1++;
	}
	while (*s2)
	{
		*dest = *s2;
		dest++;
		s2++;
	}
	*dest = '\0';
	return (ori_dest);
}
