/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:57:25 by jkarras           #+#    #+#             */
/*   Updated: 2024/07/25 16:00:08 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**split_input(char *s)
{
	char	**arr;
	int		array[4096];
	int		i;
	int		x;
	int		start;
	int		end;
	int		length;

	arr = (char **)malloc(sizeof(char *) * (count_words(s) + 1));
	if (arr == NULL)
		return (NULL);
	fill_array(s, array);
	i = 0;
	x = 0;
	while (i < count_words(s))
	{
		start = array[x];
		end = array[x + 1];
		length = end - start;
		arr[i] = (char *)malloc(sizeof(char) * (length + 1));
		if (arr[i] == NULL)
			return (NULL); /*free_part_char_arraty,*/
		ft_strlcpy(arr[i], &s[start], length + 1);
		x += 2;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

int	*fill_array(const char *str, int array[4096])
{
	int		i;
	int		in_word;
	int		in_dquote;
	int		in_quote;
	int		x;

	ft_memset(array, 0, 4096 * sizeof(int));
	i = 0;
	x = 0;
	in_word = 0;
	in_dquote = 0;
	in_quote = 0;
	while (str[i])
	{
		if (str[i] == '"' && !in_quote)
			in_dquote = !in_dquote;
		else if (str[i] == '\'' && !in_dquote)
			in_quote = !in_quote;
		if (!ft_isspace(str[i]) && !in_word)
		{
			in_word = 1;
			//ft_printf("Start %d\n", i);
			array[x] = i;
			x++;
		}
		if (in_word && (ft_isspace(str[i + 1]) || str[i + 1] == '\0') && !in_dquote && !in_quote)
		{
			in_word = 0;
			//ft_printf("End %d\n", i + 1);
			array[x] = i + 1;
			x++;
		}
		i++;
	}
	return (array);
}

int	count_words(const char *str)
{
	int		i;
	int		in_word;
	int		in_dquote;
	int		in_quote;
	int		word_count;

	i = 0;
	in_word = 0;
	in_dquote = 0;
	in_quote = 0;
	word_count = 0;
	while (str[i])
	{
		if (str[i] == '"' && !in_quote)
			in_dquote = !in_dquote;
		else if (str[i] == '\'' && !in_dquote)
			in_quote = !in_quote;
		if (!ft_isspace(str[i]) && !in_word)
		{
			in_word = 1;
			word_count++;
		}
		else if (ft_isspace(str[i]) && !in_dquote && !in_quote)
			in_word = 0;
		i++;
	}
	return (word_count);
}

int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}
