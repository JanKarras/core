/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_help3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:40:53 by rmatthes          #+#    #+#             */
/*   Updated: 2024/07/25 17:09:22 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*create_env_var(const char *name, const char *value)
{
	char	*env_var;
	size_t	name_len;
	size_t	value_len;

	name_len = ft_strlen(name);
	value_len = ft_strlen(value);
	env_var = (char *)malloc(name_len + value_len + 2); // +2 for '=' and '\0'
	if (env_var == NULL)
		return (NULL);
	ft_strcpy(env_var, name);
	ft_strcat(env_var, "=");
	ft_strcat(env_var, value);
	return (env_var);
}

void	ft_set_env_value(char *name, char *value, char **env)
{
	char	*env_var;
	int		i;

	i = 0;
	while (env[i])
	{
		if (strncmp(name, env[i], strlen(name)) == 0
			&& env[i][strlen(name)] == '=')
		{
			free(env[i]);
			env_var = create_env_var(name, value);
			if (env_var == NULL)
				return; // Handle memory allocation failure
			env[i] = env_var;
			return ;
		}
		i++;
	}
	env_var = create_env_var(name, value);
	if (env_var == NULL)
		return; // Handle memory allocation failure
	env[i] = env_var;
	env[++i] = NULL;
}

int	ft_charsize(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}
