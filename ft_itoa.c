/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:19:37 by wpepping          #+#    #+#             */
/*   Updated: 2024/05/31 15:49:30 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nr_of_chars(int n)
{
	int	i;
	int	pow;

	i = 1;
	pow = 1;
	if (n == -2147483648)
		n = n + 1;
	if (n < 0)
	{
		n = 0 - n;
		i += 1;
	}
	while (n / pow >= 10)
	{
		i++;
		pow *= 10;
	}
	return (i);
}

static void	recursion(long n, char *result, int pos)
{
	if (n > 9)
	{
		result[pos] = '0' + (n % 10);
		recursion(n / 10, result, pos - 1);
	}
	else
		result[pos] = '0' + n;
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	nn;

	len = nr_of_chars(n);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	nn = n;
	if (nn < 0) {
		result[0] = '-';
		nn = 0 - nn;
	}
	recursion(nn, result, len - 1);
	result[len] = '\0';
	return (result);
}
