/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:29:13 by afaby             #+#    #+#             */
/*   Updated: 2022/04/05 17:39:58 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_slen(const char *s)
{
	int	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

static int	count_words(const char *s, char c)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			n++;
		}
		else
			i++;
	}
	return (n);
}

static char	*isolation(int start, int end, const char *s)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * (end - start) + 1);
	if (!tmp)
		return (NULL);
	while (start < end)
	{
		*(tmp + i) = *(s + start);
		start++;
		i++;
	}
	*(tmp + i) = '\0';
	return (tmp);
}

void	init_vars(int *start, int *i, int *n, int *end)
{
	*start = 0;
	*i = -1;
	*n = 0;
	*end = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**list;
	int		start;
	int		end;
	int		i;
	int		n;

	init_vars(&start, &i, &n, &end);
	list = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!list)
		return (NULL);
	while (*(s + ++i))
	{
		if (*(s + i) == c)
		{
			end = i;
			if ((start != end))
				*(list + n++) = isolation(start, end, s);
			start = end + 1;
		}
	}
	if (start != ft_slen(s))
		*(list + n++) = isolation(start, ft_slen(s), s);
	list[n] = 0;
	return (list);
}
