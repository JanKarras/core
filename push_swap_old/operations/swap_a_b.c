/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:21:29 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/01 16:13:34 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa_or_sb_ss(t_list *list)
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

void	ss(t_list *stack_a, t_list *list)
{
	ft_putendl_fd("ss", 1);
	sa_or_sb_ss(stack_a);
	sa_or_sb_ss(list);
}
