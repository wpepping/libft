/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:23:25 by wpepping          #+#    #+#             */
/*   Updated: 2024/04/24 12:05:44 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	int		i;

	result = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			result = ((char *)&s[i]);
		s++;
	}
	if ((char)c == '\0')
		result = ((char *)&s[i]);
	return (result);
}
