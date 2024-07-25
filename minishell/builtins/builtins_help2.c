/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_help2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:39:25 by rmatthes          #+#    #+#             */
/*   Updated: 2024/07/25 17:12:12 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*original_dest;

	original_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*original_dest;

	original_dest = dest;

	while (*dest)
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (original_dest);
}

void	free_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

void	remove_env_var(char **env, int index)
{
	int		j;
	char	**new_env;

	new_env = (char **)malloc(sizeof(char *) * ft_charsize(env));
	if (!new_env)
		return ;

	j = 0;
	while (env[j])
	{
		if (j != index)
		{
			new_env[j] = ft_strdup(env[j]);
			if (!new_env[j])
			{
				free_envp(new_env);
				return ;
			}
		}
		j++;
	}
	new_env[j] = NULL;
	free_envp(env);
	env = new_env;
}
