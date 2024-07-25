/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_help1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:02:53 by rmatthes          #+#    #+#             */
/*   Updated: 2024/07/25 17:09:17 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_nb_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return (i);
	else
		return (-1);
}

int	nb_args(char **args)
{
	int		size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_cd_help(char **cmd, char **env)
{
	char	*old_pwd;
	char	new_pwd[4096];
	char	*oldpwd;

	old_pwd = get_env_value("PWD", env);
	if (ft_strcmp(cmd[1], "~") == 0)
		chdir(get_env_value("HOME", env));
	else if (ft_strcmp(cmd[1], "/") == 0)
		chdir("/");
	else if (ft_strcmp(cmd[1], "-") == 0)
	{
		oldpwd = get_env_value("OLDPWD", env);
		chdir(oldpwd);
	}
	else
		chdir(cmd[1]);
	if (getcwd(new_pwd, sizeof(new_pwd)) != NULL)
	{
		ft_set_env_value("OLDPWD", old_pwd, env);
		ft_set_env_value("PWD", new_pwd, env);
	}
	free(old_pwd);
}
