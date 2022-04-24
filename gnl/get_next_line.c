/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:10:27 by afaby             #+#    #+#             */
/*   Updated: 2022/04/24 17:24:19 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cut_str(char *to_process)
{
	int		i;
	char	*res;
	int		j;

	i = 0;
	while (to_process[i] && to_process[i] != '\n')
		i++;
	if (to_process[i] == 0)
	{
		free(to_process);
		return (0);
	}
	res = malloc(ft_strlen(to_process) - i + 1);
	if (!res)
		return (NULL);
	i++;
	j = 0;
	while (to_process[i])
		res[j++] = to_process[i++];
	res[j] = 0;
	free(to_process);
	return (res);
}

static char	*get_subline(char *to_process)
{
	int		i;
	char	*res;

	i = 0;
	if (!*to_process)
		return (0);
	while (to_process[i] && to_process[i] != '\n')
		i++;
	if (to_process[i] == '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (to_process[++i] && to_process[i] != '\n')
		res[i] = to_process[i];
	if (to_process[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd, int buffer_size)
{
	char		*res;
	static char	*to_process[1025];
	char		*buf;
	int			ret;

	buf = malloc(sizeof(char) * (buffer_size + 1));
	if (!buf)
		return (0);
	ret = 1;
	while (ret && !ft_strchr(to_process[fd], '\n'))
	{
		ret = read(fd, buf, buffer_size);
		if (ret < 0)
		{
			free(buf);
			return (0);
		}
		buf[ret] = '\0';
		to_process[fd] = ft_strjoin(to_process[fd], buf);
	}
	free(buf);
	res = get_subline(to_process[fd]);
	to_process[fd] = cut_str(to_process[fd]);
	return (res);
}
