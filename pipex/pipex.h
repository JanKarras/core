/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:45:46 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/08 15:24:29 by jkarras          ###   ########.fr       */
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
}	t_data;

int		init(char **argv, t_data *data);
void	free_data(t_data *data);

#endif
