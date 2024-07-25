/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:50:15 by rmatthes          #+#    #+#             */
/*   Updated: 2024/07/25 17:09:28 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_quotes(char *str, char quote_char);
void	replace_variables(char *str, char **env);
char	*get_env_var(char *var, char **env);

void	remove_quotes(char *str, char quote_char)
{
	char	*src;
	char	*dst;

	src = str;
	dst = str;
	while (*src)
	{
		if (*src != quote_char)
		{
			*dst = *src;
			dst++;
		}
		src++;
	}
	*dst = '\0';
}

void	replace_variables(char *str, char **env)
{
	char	buffer[1024];
	char	*src = str;
	char	*dst = buffer;
	char	*var_start;
	char	var_name[256];
	char	*value;

	while (*src)
	{
		if (*src == '$' && (isalnum(*(src + 1)) || *(src + 1) == '_'))
		{
			src++;
			var_start = src;
			while (isalnum(*src) || *src == '_')
				src++;
			strncpy(var_name, var_start, src - var_start);
			var_name[src - var_start] = '\0';
			value = get_env_var(var_name, env);
			if (value)
				while (*value)
					*dst++ = *value++;
		}
		else
			*dst++ = *src++;
	}
	*dst = '\0';
	strcpy(str, buffer);
}

char	*get_env_var(char *var, char **env)
{
	int		len;
	int		i;

	len = strlen(var);
	i = 0;
	while (env[i] != NULL)
	{
		if (strncmp(env[i], var, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}

void	ft_echo(t_data *data)
{
	int		i;
	int		n_flag;
	char	*arg;
	int		in_dquote;
	int		in_quote;
	char	**args;
	char	**env;

	args = (data->cmds)[0].argv;
	env = data->envp;
	i = 1;
	n_flag = 0;
	if (nb_args(args) < 2
		|| (ft_strcmp(args[1], "-n") == 0 && nb_args(args) == 2))
		return ;
	if (ft_strcmp(args[1], "-n") == 0)
	{
		n_flag = 1;
		i++;
	}
	while (args[i])
	{
		in_dquote = 0;
		in_quote = 0;
		if (args[i][0] == '"')
			in_dquote = 1;
		else if (args[i][0] == '\'')
			in_quote = 1;
		arg = strdup(args[i]);
		if (!arg)
			return ;
		if (in_dquote)
		{
			replace_variables(arg, env);
			remove_quotes(arg, '"');
		}
		else if (in_quote)
			remove_quotes(arg, '\'');
		else
			replace_variables(arg, env);
		printf("%s", arg);
		if (args[i + 1])
			printf(" ");
		free(arg);
		i++;
	}
	if (!n_flag)
		printf("\n");
}
