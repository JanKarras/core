/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:55:43 by jkarras           #+#    #+#             */
/*   Updated: 2024/07/25 17:14:00 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parse_single_cmd(t_data *data)
{
	cut_fds(data);
	data->cmd_nb = 1;
	(data->cmds)[0].argv = data->split_input;
	if (!is_builtin((data->cmds)[0].argv))
		ft_process_builtin(data);
	else
		process_s_cmd(data);
}
