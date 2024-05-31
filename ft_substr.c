/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:25:59 by wpepping          #+#    #+#             */
/*   Updated: 2024/05/31 12:44:32 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	strlen;
	size_t	remaining_strlen;

	if (s == NULL)
		return (NULL);
	strlen = ft_strlen(s);
	if ((strlen == 0 && start > 0) || start > strlen)
		start = strlen;
	remaining_strlen = ft_strlen(s + start);
	if (len > remaining_strlen)
		len = remaining_strlen;
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}
