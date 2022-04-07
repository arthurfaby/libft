/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:51:09 by afaby             #+#    #+#             */
/*   Updated: 2022/04/06 09:43:22 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnew_loc(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*tmp;

	n_lst = ft_lstnew_loc((*f)(lst->content));
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew_loc((*f)(lst->content));
		ft_lstadd_back(&n_lst, tmp);
		if (!tmp)
		{
			ft_lstclear(&n_lst, del);
			return (0);
		}
		lst = lst->next;
	}
	return (n_lst);
}
