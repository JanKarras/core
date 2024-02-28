/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:07:44 by jkarras           #+#    #+#             */
/*   Updated: 2024/01/15 17:22:09 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void (*del)(void *))
{
	t_list	*new_list;
	t_list	*lst_start;

	if (lst == NULL || del == NULL)
		return (NULL);
	new_list = ft_lstnew(lst->content);
	if (new_list == NULL)
		return (NULL);
	lst_start = new_list;
	lst = lst->next;
	while (lst != NULL)
	{
		new_list->next = ft_lstnew(lst->content);
		if (new_list->next == NULL)
		{
			ft_lstclear(&lst_start, del);
			return (NULL);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	new_list->next = NULL;
	return (lst_start);
}
