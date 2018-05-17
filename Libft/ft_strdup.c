/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:50:18 by mguyout           #+#    #+#             */
/*   Updated: 2017/10/20 08:49:05 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ls.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = -1;
	if (!(s2 = ft_xalloc((sizeof(char) * (ft_strlen(s1) + 1)), 0)))
		return (NULL);
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}
