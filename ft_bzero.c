/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:38:11 by wpepping          #+#    #+#             */
/*   Updated: 2024/04/17 17:56:24 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*p;

	i = 0;
	p = s;
	while (i < n)
	{
		*(p + i) = '\0';
		i++;
	}
	return (s);
}
