/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:59:17 by wpepping          #+#    #+#             */
/*   Updated: 2024/05/13 18:43:25 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_chars(const char *str, char c, int *pos, int skip_word)
{
	if (skip_word)
	{
		while (str[*pos] != '\0' && str[*pos] != c)
			*pos += 1;
	}
	else
	{
		while (str[*pos] != '\0' && str[*pos] == c)
			*pos += 1;
	}
}

static char	*read_word(const char *str, char c, int *pos)
{
	int		i;
	int		len;
	char	*result;

	len = 0;
	while (str[*pos + len] != '\0' && str[*pos + len] != c)
		len++;
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		result[i++] = str[(*pos)++];
	result[i] = '\0';
	return (result);
}

static int	count_parts(const char *str, char c)
{
	int	pos;
	int	result;

	pos = 0;
	result = 0;
	skip_chars(str, c, &pos, 0);
	while (str[pos] != '\0')
	{
		result++;
		skip_chars(str, c, &pos, 1);
		skip_chars(str, c, &pos, 0);
	}
	return (result);
}

static void	free_result(char **result)
{
	int	i;

	i = 0;
	while (result[i] != NULL)
		free(result[i++]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	int		n;
	int		i;
	int		pos;
	char	**result;

	n = count_parts(s, c);
	result = malloc((n + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < n)
	{
		skip_chars(s, c, &pos, 0);
		result[i] = read_word(s, c, &pos);
		if (result[i] == NULL)
		{
			free_result(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
