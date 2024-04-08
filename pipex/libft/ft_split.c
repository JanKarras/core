/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:47:31 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/14 15:51:03 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static void	fill_arr(char const *s, char c, size_t i, char **arr)
{
	size_t	len;

	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (ft_strchr(s, c) == NULL)
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			arr[i] = ft_substr(s, 0, len);
			i++;
			s = s + len;
		}
	}
	arr[i] = NULL;
}

char	**ft_split(char *s, char c)
{
	char	**arr;

	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (s == NULL || arr == NULL)
		return (NULL);
	fill_arr(s, c, 0, arr);
	return (arr);
}
