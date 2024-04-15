/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:45:46 by jkarras           #+#    #+#             */
/*   Updated: 2024/04/15 13:09:57 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "libft/libft.h"

void	error(int key, int fd);
char	*find_path(char *cmd_name, char **envp, char **paths, char *path);
void	execute(char *argv, char **envp, int key, int fd);
#endif
