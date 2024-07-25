/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:37:45 by jkarras           #+#    #+#             */
/*   Updated: 2024/06/20 13:37:51 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_list(t_envp **list)
{
	t_envp	*temp;
	t_envp	*current;

	if (*list == NULL || list == NULL)
		return ;
	current = *list;
	while (current != NULL)
	{
		temp = current->next;
		free(current->key_str);
		free(current);
		current = temp;
	}
	list = NULL;
}

t_envp	*init_envp(char **envp)
{
	t_envp	*list;
	size_t	i;

	i = 0;
	list = NULL;
	while (envp[i])
	{
		if (append_list(&list, envp[i]) != 0)
			return (clear_list(&list), NULL);
		i++;
	}
	return (list);
}

int	append_list(t_envp **list, char *str)
{
	t_envp	*new_node;
	t_envp	*ori;

	new_node = (t_envp *)malloc(sizeof(t_envp));
	if (new_node == NULL)
		return (1);
	new_node->key_str = ft_strdup(str);
	if (new_node->key_str == NULL)
		return (free(new_node), 1);
	new_node->next = NULL;
	if (*list == NULL)
	{
		*list = new_node;
		return (0);
	}
	ori = *list;
	while (ori->next != NULL)
		ori = ori->next;
	ori->next = new_node;
	return (0);
}
