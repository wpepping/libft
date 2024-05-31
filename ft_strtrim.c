/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:02:38 by wpepping          #+#    #+#             */
/*   Updated: 2024/04/19 15:06:22 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isin(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	size_t			strlen;
	unsigned int	trim_end;
	char			*result;

	strlen = ft_strlen(s1);
	i = strlen;
	trim_end = 0;
	if (strlen > 0)
		while (i > 0 && isin(set, s1[--i]))
			trim_end++;
	i = 0;
	if (trim_end != strlen)
		while (*s1 != '\0' && isin(set, s1[i]))
			i++;
	strlen = strlen - i - trim_end;
	result = malloc((strlen + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1 + i, strlen);
	result[strlen] = '\0';
	return (result);
}
