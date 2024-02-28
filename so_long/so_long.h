/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:34:38 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/27 13:46:59 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "./libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**argv;
	void	**img_ptrs;
	int		*col;
	int		*e_x;
	int		*e_y;
	int		*move_count;
}	t_data;

typedef struct s_point
{
	int		*x;
	int		*y;
}	t_point;

//create_map
int		check_param(char *file_name);
char	*read_map(int fd);
int		check_empty_line(char *text);
//check_map
int		check_map(char **map);
int		check_size(char **map);
int		check_walls(char **map, int len, int height);
int		check_player_exit(char **map, int i, int j);
int		check_chars(char **map);
int		check_path_is_valid(char **argv, int len, int height);
//check_map_utils
int		my_ft_strlen(char *s);
int		get_height(char **map);
int		check_char(char c);
//start game
int		start_game(char **argv);
//free
void	free_argv(char **argv);
#endif
