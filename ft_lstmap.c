/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:38:08 by wpepping          #+#    #+#             */
/*   Updated: 2024/05/31 13:12:02 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*free_and_return_null(
	void *c,
	t_list **lst,
	void (*del)(void *))
{
	(*del)(c);
	if (lst != NULL)
		ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*curr;
	void	*new_content;

	if (lst == NULL)
		return (NULL);
	new_content = (*f)(lst->content);
	result = ft_lstnew(new_content);
	if (result == NULL)
		return (free_and_return_null(new_content, NULL, del));
	curr = result;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new_content = (*f)(lst->content);
		curr->next = ft_lstnew(new_content);
		if (curr->next == NULL)
			return (free_and_return_null(new_content, &result, del));
		curr = curr->next;
	}
	return (result);
}
