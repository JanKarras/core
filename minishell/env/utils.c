/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:38:44 by jkarras           #+#    #+#             */
/*   Updated: 2024/07/25 16:29:18 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env_value(const char *key, char **env)
{
	size_t	key_len;
	char	*value;

	if (key == NULL || env == NULL)
		return (NULL);
	key_len = ft_strlen(key);
	while (*env)
	{
		if (ft_strncmp(*env, key, key_len) == 0 && (*env)[key_len] == '=')
		{
			value = *env + key_len + 1;
			return (ft_strdup(value));
		}
		env++;
	}
	return (NULL);
}
