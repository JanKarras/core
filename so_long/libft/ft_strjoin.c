/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:24:33 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/08 16:58:30 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	char	*ori_dest;
	char	*ori_s1;

	dest = (char *)malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (dest == NULL)
		return (NULL);
	ori_dest = dest;
	ori_s1 = s1;
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
	free(ori_s1);
	*dest = '\0';
	return (ori_dest);
}
