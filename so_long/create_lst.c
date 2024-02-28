/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:05:27 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/20 15:05:38 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*create_new_node(char c, int y, int x)
{
	t_list	*new;
	char	*content_ptr;
	int		*x_ptr;
	int		*y_ptr;

	content_ptr = (char *)malloc(sizeof(char) + 1);
	if (content_ptr == NULL)
		return (NULL);
	x_ptr = (int *)malloc(sizeof(int));
	if (x_ptr == NULL)
		return (free(content_ptr), NULL);
	y_ptr = (int *)malloc(sizeof(int));
	if (y_ptr == NULL)
		return (free(content_ptr), free(x_ptr), NULL);
	content_ptr[0] = c;
	content_ptr[1] = '\0';
	*y_ptr = y;
	*x_ptr = x;
	new = ft_lstnew(content_ptr, x_ptr, y_ptr);
	if (new == NULL)
		return (free(content_ptr), free(x_ptr), free(y_ptr), NULL);
	return (new);
}

void	clear_map(t_list ***lst_map, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		ft_lstclear(&((*lst_map)[j]), free);
		j++;
	}
}

int	create_list(t_list **row, char **argv, int len, int y)
{
	int		i;
	t_list	*new_node;

	i = 0;
	while (i < len)
	{
		new_node = create_new_node(argv[y][i], y, i);
		if (new_node == NULL)
			return (ft_lstclear(row, free), -1);
		ft_lstadd_back(row, new_node);
		i++;
	}
	return (0);
}

void	set_null(t_list	**lst_map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		lst_map[i] = NULL;
		i++;
	}
}

void	set_previus(t_list	*lst_map)
{
	t_list	*temp;

	lst_map->previus = NULL;
	while (lst_map != NULL)
	{
		temp = lst_map->next;
		if (temp == NULL)
			break ;
		temp->previus = lst_map;
		lst_map = lst_map->next;
	}
}

void	set_above_beneath_top_bot(t_list *collum, t_list **lst_map, int height, int y)
{
	if (y == 0)
	{
		while (collum != NULL)
		{
			collum->above = NULL;
			collum->beneathe = lst_map[1];
			lst_map[1] = lst_map[1]->next;
			collum = collum->next;
		}
	}
	else
	{
		while (collum != NULL)
		{
			collum->beneathe = NULL;
			collum->above = lst_map[height - 1];
			lst_map[height - 1] = lst_map[height - 1]->next;
			collum = collum->next;
		}
	}
}

void	set_above_beneath(t_list *collum, t_list **lst_map, int y)
{
	while (collum != NULL)
	{
		collum->above = lst_map[y - 1];
		collum->beneathe = lst_map[y + 1];
		lst_map[y] = lst_map[y]->next;
		collum = collum->next;
	}

}

void	set_directions(t_list **lst_map, int height, int len)
{
	int	i;

	i = 0;
	len = 0;
	while (i < height)
	{
		set_previus(lst_map[i]);
		if (i == 0 || i == height - 1)
			set_above_beneath_top_bot(lst_map[i], lst_map, height, i);
		// else
		// 	set_above_beneath(lst_map[i], lst_map, i);
		write(1, "t", 1);
		i++;
	}
}

int	init_map_lst(t_list ***lst_map, char **argv, int len, int height)
{
	int	i;

	*lst_map = (t_list **)malloc(sizeof(t_list *) * (height));
	if (*lst_map == NULL)
		return (-1);
	set_null(*lst_map, height);
	i = 0;
	while (i < height)
	{
		if (create_list(&((*lst_map)[i]), argv, len, i) == -1)
			return (clear_map(lst_map, i), free(*lst_map), -1);
		i++;
	}
	set_directions(*lst_map, height, len);
	return (0);
}

void	print_tlist_next(t_list *stack)
{
	while (stack != NULL)
	{
		printf("%s ", stack->content);
		stack = stack->next;
	}
	printf("\n");
}

void	print_tlist_pre(t_list *stack)
{
	stack = ft_lstlast(stack);
	while (stack != NULL)
	{
		printf("%s ", stack->content);
		stack = stack->previus;
	}
	printf("\n");
}

void	print_map(t_list **map_lst, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		print_tlist_next(map_lst[i]);
		i++;
	}
}

void	print_map_reversed(t_list **map_lst, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		print_tlist_pre(map_lst[i]);
		i++;
	}
}
