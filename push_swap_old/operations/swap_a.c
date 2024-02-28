/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:04:29 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/01 16:13:37 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list *list)
{
	t_list	*second_node;
	int		*tmp;

	ft_putendl_fd("sa", 1);
	if (list == NULL)
		return ;
	second_node = list->next;
	if (second_node == NULL)
		return ;
	tmp = list->content;
	list->content = second_node->content;
	second_node->content = tmp;
}
