/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:55:44 by afaby             #+#    #+#             */
/*   Updated: 2022/04/11 10:51:43 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base_validity(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == '-' || *(str + i) == '+')
			return (0);
		j = 1;
		while (*(str + i + j))
		{
			if (*(str + i) == *(str + i + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(long long int nbr, char *base)
{
	int	base_len;

	if (check_base_validity(base))
	{
		base_len = ft_strlen(base);
		if (nbr == -2147483648)
		{
			ft_putnbr_base(nbr / base_len, base);
			ft_putchar(base[nbr % base_len]);
			return ;
		}
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		if (nbr < base_len)
			ft_putchar(base[nbr]);
		else
		{
			ft_putnbr_base(nbr / base_len, base);
			ft_putnbr_base(nbr % base_len, base);
		}
	}
}
