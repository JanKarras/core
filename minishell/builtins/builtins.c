/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:36:33 by rmatthes          #+#    #+#             */
/*   Updated: 2024/07/25 17:28:05 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(t_data *data)
{
	char	*pwd;

	pwd = get_env_value("PWD", data->envp);
	if (pwd)
		printf("%s\n", pwd);
	else
		printf("PWD not found in environment.\n");
}

void	ft_cd(t_data *data)
{
	char	*old_pwd;
	char	*new_pwd;

	old_pwd = get_env_value("PWD", data->envp);
	if (nb_args((data->cmds)[0].argv) > 2 || (data->cmds)[0].argv[1] == NULL)
	{
		write(1, "thats not how it works\n", 24);
		free(old_pwd);
		return ;
	}
	ft_cd_help((data->cmds)[0].argv, data->envp);
	new_pwd = get_env_value("PWD", data->envp);
	if (new_pwd)
		free(new_pwd);
	free(old_pwd);
}

void	ft_export(t_data *data)
{
	int		i;
	char	**tmp;
	char	**cmd;
	char	**env;

	i = 1;
	cmd = (data->cmds)[0].argv;
	env = data->envp;
	while (cmd[i])
	{
		if (ft_strchr(cmd[i], '=') != NULL)
		{
			tmp = ft_split(cmd[i], '=');
			if (tmp[0] && tmp[1])
				ft_set_env_value(tmp[0], tmp[1], env);
			free(tmp[0]);
			free(tmp[1]);
			free(tmp);
		}
		i++;
	}
}

void	ft_unset(t_data *data)
{
	int		i;
	char	**cmd;
	char	**env;

	cmd = (data->cmds)[0].argv;
	env = data->envp;
	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], cmd[1], ft_strlen(cmd[1])) != NULL)
		{
			del_index_char(data->envp, i);
			return ;
		}
		i++;
	}
}

void	ft_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
