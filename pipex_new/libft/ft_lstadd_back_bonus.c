/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:28:27 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/15 16:17:37 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_last_ptr;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	lst_last_ptr = ft_lstlast(*lst);
	lst_last_ptr->next = new;
}
