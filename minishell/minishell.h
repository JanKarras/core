/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:58:04 by jkarras           #+#    #+#             */
/*   Updated: 2024/07/25 17:28:28 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_envp
{
	char			*key_str;
	struct s_envp	*next;
}	t_envp;

typedef struct s_cmd
{
	char	*path;
	char	**argv;
}	t_cmd;

typedef struct s_data
{
	int			last_exit;
	size_t		cmd_nb;
	char		*input;
	char		**split_input;
	char		**envp;
	t_cmd		cmds[4096];
	char		infile[4096];
	char		outfile[4096];
}	t_data;


char	*get_key_value(t_envp *envp, char *key);
void	print_list(t_envp *list);
void	clear_list(t_envp **list);
t_envp	*init_envp(char **envp);
int		append_list(t_envp **list, char *str);

//env
char	**copy_envp(char **envp);
//env_utils
char	*get_env_value(const char *key, char **env);
//exit
void	exit_programm(t_data *data);
//input
char	*get_input(t_data *data);
void	set_input_output(t_data *data);
//input_utils
char	**split_input(char *s);
int		*fill_array(const char *str, int array[4096]);
int		count_words(const char *str);
int		ft_isspace(char c);
//parse_single
int		parse_single_cmd(t_data *data);
//parse_single_utils
void	cut_fds(t_data *data);
void	del_index(t_data *data, size_t i);
void	del_index_char(char **arr, size_t i);
int		is_builtin(char **cmd);
//parse_multi
int		parse_multi_cmd(t_data *data);
//process_utils
char	*find_path(char *cmd_name, char **envp, char **paths, char *path);
//process_builtin
void	ft_process_builtin(t_data *data);
//process_single
void	process_s_cmd(t_data *data);
//builtins
void	ft_pwd(t_data *data);
void	ft_cd(t_data *data);
void	ft_export(t_data *data);
void	ft_unset(t_data *data);
int		ft_nb_strchr(char *s, char c);
int		nb_args(char **args);
int		ft_strcmp(char *s1, char *s2);
void	ft_cd_help(char **cmd, char **env);
char	*get_env_value(const char *key, char **env);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
void	free_envp(char **envp);
void	remove_env_var(char **env, int index);
char	*create_env_var(const char *name, const char *value);
void	ft_set_env_value(char *name, char *value, char **env);
int		ft_charsize(char **env);
void	ft_echo(t_data *data);
void	ft_env(char **env);
#endif
