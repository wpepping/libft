/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:36:08 by wpepping          #+#    #+#             */
/*   Updated: 2024/04/26 16:34:28 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*p;

	if (dest == NULL && src == NULL)
		return (dest);
	i = 0;
	p = dest;
	if (dest > src)
	{
		while (i < n)
		{
			*(p + n - i - 1) = *(unsigned char *)(src + n - i - 1);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			*(p + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	return (dest);
}
