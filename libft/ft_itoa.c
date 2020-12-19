/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:59:27 by emenella          #+#    #+#             */
/*   Updated: 2020/11/29 04:19:18 by emenella         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long int n)
{
	long int i;

	i = 0;
	if (n <= 0)
	{
		n = -n;
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_power(long int nb, long int power)
{
	long int i;
	long int result;

	i = 0;
	result = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	--power;
	result *= ft_power(nb, power);
	return (result);
}

char		*ft_itoa(int n)
{
	int			i;
	int			len;
	int			chr;
	long int	nbr;
	char		*str;

	i = 0;
	nbr = (long int)n;
	len = ft_len(nbr);
	if (!(str = malloc(sizeof(char) * (len-- + 1))))
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		str[i++] = '-';
	}
	while (i != len)
	{
		chr = nbr / ft_power(10, len - i);
		nbr -= chr * ft_power(10, len - i);
		str[i++] = chr + '0';
	}
	str[i++] = nbr + '0';
	str[i] = '\0';
	return (str);
}
