/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:19:27 by jkarras           #+#    #+#             */
/*   Updated: 2024/01/10 16:37:36 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb_bonus(t_list *list)
{
	t_list	*second_node;
	int		*tmp;

	if (list == NULL)
		return ;
	second_node = list->next;
	if (second_node == NULL)
		return ;
	tmp = list->content;
	list->content = second_node->content;
	second_node->content = tmp;
}
