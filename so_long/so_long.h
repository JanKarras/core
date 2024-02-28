/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:34:38 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/28 19:43:12 by jkarras          ###   ########.fr       */
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
	void	**img_ptrs;
	char	*o;
	char	*n;
	char	**argv;
	int		*col;
	int		*e_x;
	int		*e_y;
	int		*move_count;
	int		*width;
	int		*height;
}	t_data;

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
int		get_p_x(char **map, int height);
int		get_p_y(char **map, int height);
int		get_e_x(char **map, int height);
int		get_e_y(char **map, int height);
int		get_collectables_count(char **map);
//check_map_utils
int		my_ft_strlen(char *s);
int		get_height(char **map);
int		check_char(char c);
//start game
int		start_game(char **argv);
//destroy
void	free_argv(char **argv);
void	free_col_on_exit(t_data *data);
void	free_img_ptrs(t_data *data, int size);
void	ft_error(t_data *data);
int		on_destroy(t_data *data);
//init
int		get_img_ptrs(t_data *data, int w, int h);
int		init_img_ptrs(t_data *data);
int		inti_new_width_height(t_data *data);
int		init_col_on_exit(t_data *data);
t_data	*init(char **argv);
//resize img
char	*get_data_addr(void *img_ptr, int *sz_l, int i);
void	resize(t_data *data, int szn, int szo, int i);
int		rezise_img(t_data *data, int new_width, int new_height, int i);
//move
void	move_up(t_data *data, int i, int j);
void	move_left(t_data *data, int i, int j);
void	move_down(t_data *data, int i, int j);
void	move_right(t_data *data, int i, int j);
void	move(t_data *data, int i, int j, int keycode);
//draw
int		get_img_index(char c);
int		draw_map(t_data *data);
void	find_player_pos(t_data *data, int keycode);
#endif
