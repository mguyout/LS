/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:05:08 by mguyout           #+#    #+#             */
/*   Updated: 2017/10/20 09:29:32 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_core(char *str, int count, int n, int lock)
{
	int		i;

	if (lock == 1)
		str[0] = '-';
	i = count;
	str[i] = '\0';
	i--;
	while (n > 9)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	str[i] = n + '0';
	return (str);
}

char		*ft_itoa(int n)
{
	int		count;
	int		cpy;
	int		neg;
	char	str[32];

	neg = 0;
	count = 1;
	if (n == -2147483648)
		return ("-2147483648");
	if (n < 0 && n != -0)
	{
		n = -n;
		count++;
		neg = 1;
	}
	cpy = n;
	while (cpy > 9)
	{
		count++;
		cpy = cpy / 10;
	}
	return (ft_itoa_core(str, count, n, neg));
}
