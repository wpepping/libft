/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:26:18 by wpepping          #+#    #+#             */
/*   Updated: 2024/04/26 16:37:56 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*p;

	if (dest == NULL && src == NULL)
		return (dest);
	i = 0;
	p = dest;
	while (i < n)
	{
		*(p + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}
