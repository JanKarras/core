/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:45:46 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/25 15:57:34 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "libft/libft.h"

typedef struct s_data
{
	char	*i;
	char	*o;
	char	*f;
	char	*s;
	char	**argv1;
	char	**argv2;
	char	**envp;
	char	*path1;
	char	*path2;
	int		*fd_in;
	int		*fd_out;
	int		*pipefd_1;
	int		*pipefd_2;
	pid_t	*cpid1;
	pid_t	*cpid2;
}	t_data;

void	ft_free_data(t_data *data);
int		init(t_data *data, char **argv);
int		create_processes(t_data *data);
int		parent_process(t_data *data);
int		check_access(t_data *data);

#endif
