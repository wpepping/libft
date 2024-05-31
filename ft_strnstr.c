/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:58:12 by wpepping          #+#    #+#             */
/*   Updated: 2024/04/19 16:00:26 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	size_t			little_len;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	j = 0;
	while (big[j] != '\0' && j + little_len <= len)
	{
		i = 0;
		while (big[j + i] != '\0' && little[i] != '\0'
			&& big[j + i] == little[i])
			i++;
		if (little[i] == '\0')
			return ((char *)&(big[j]));
		j++;
	}
	return (NULL);
}
