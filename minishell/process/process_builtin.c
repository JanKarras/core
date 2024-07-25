/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:14:42 by jkarras           #+#    #+#             */
/*   Updated: 2024/07/25 17:16:07 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_process_builtin(t_data *data)
{
	if (ft_strcmp((data->cmds)[0].argv[0], "pwd") == 0)
		ft_pwd(data);
	else if (ft_strcmp((data->cmds)[0].argv[0], "echo") == 0)
		ft_echo(data);
	else if (ft_strcmp((data->cmds)[0].argv[0], "cd") == 0)
		ft_cd(data);
	else if (ft_strcmp((data->cmds)[0].argv[0], "export") == 0)
		ft_export(data);
	else if (ft_strcmp((data->cmds)[0].argv[0], "env") == 0)
		ft_env(data->envp);
	else if (ft_strcmp((data->cmds)[0].argv[0], "unset") == 0)
		ft_unset(data);
}
