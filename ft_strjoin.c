/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:12:41 by afaby             #+#    #+#             */
/*   Updated: 2022/04/02 10:30:19 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_bzero_loc(void *s, size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	res = s;
	while (i < n)
	{
		*(res + i) = '\0';
		i++;
	}
}

static int	ft_strlen_loc(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static void	ft_strcat(char *dest, const char *src)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)src;
	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (tmp[j] != '\0')
	{
		dest[i] = tmp[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	res = malloc(ft_strlen_loc(s1) + ft_strlen_loc(s2) + 1);
	if (res == NULL)
		return (NULL);
	ft_bzero_loc(res, ft_strlen_loc(s1) + ft_strlen_loc(s2) + 1);
	ft_strcat(res, s1);
	ft_strcat(res, s2);
	return (res);
}
