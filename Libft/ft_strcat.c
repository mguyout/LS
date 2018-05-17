/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:11:33 by mguyout           #+#    #+#             */
/*   Updated: 2017/10/25 04:51:55 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ls.h"

char	*ft_strcat(char *s1, char *s2)
{
	int		i;
	int		x;
	int		j;
	int		k;
	char	*str;

	k = -1;
	j = -1;
	i = ft_strlen(s1);
	x = ft_strlen(s2);
	str = ft_xalloc((sizeof(char) * (i + x + 3)), 0);
	while (++j != i)
		str[j] = s1[j];
	str[j] = '/';
	while (++j < i + x + 2)
		str[j] = s2[++k];
	str[j] = '\0';
	return (str);
}
