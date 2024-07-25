/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:37:52 by jkarras           #+#    #+#             */
/*   Updated: 2024/06/20 13:57:46 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_key_value(t_envp *envp, char *key)
{
	char	*value;

	while (ft_strnstr(envp->key_str, key, ft_strlen(key)) == NULL)
	{
		envp = envp->next;
		if (envp == NULL)
			return (NULL);
	}
	value = ft_substr(envp->key_str, ft_strlen(key)
			+ 1, ft_strlen(envp->key_str) - ft_strlen(key) - 1);
	return (value);
}

void	print_list(t_envp *list)
{
	while (list != NULL)
	{
		ft_putendl_fd(list->key_str, 1);
		list = list->next;
	}
}
