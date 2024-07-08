/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:58:56 by wpepping          #+#    #+#             */
/*   Updated: 2024/05/31 16:59:59 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *begin_list, void *ref, int (*cmp)())
{
	while (begin_list != NULL)
	{
		if ((*cmp)(begin_list->content, ref) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}
