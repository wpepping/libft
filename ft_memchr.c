/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:59:45 by wpepping          #+#    #+#             */
/*   Updated: 2024/04/24 11:39:25 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	const unsigned char	*src;

	i = 0;
	src = s;
	while (i < n)
	{
		if ((unsigned char)*(src + i) == (unsigned char)c)
			return ((void *)&(src[i]));
		i++;
	}
	return (NULL);
}
