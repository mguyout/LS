/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallocat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 06:58:05 by mguyout           #+#    #+#             */
/*   Updated: 2017/10/22 10:18:31 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "Libft/libft.h"

void			*ft_xalloc(size_t size, int ref)
{
	t_xmap	*map;

	if (!(map = ft_xmap(ref, 0)))
		exit(1);
	if (map->ptr + 1 < map->size)
	{
		map->map[map->ptr] = ft_salloc(size);
		return (map->map[map->ptr++]);
	}
	ft_xmap(ref, 2);
	return (ft_xalloc(size, ref));
}

void			ft_xclear(int ref)
{
	t_xmap	*map;

	if (!(map = ft_xmap(ref, 0)))
		return ;
	while (map->ptr--)
	{
		if (map->map[map->ptr])
			free(map->map[map->ptr]);
	}
	ft_xmap(ref, 3);
}

char			*ft_strcat2(char *s1, char *s2)
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
	if (!(str = ft_xalloc((sizeof(char) * i + x + 3), 0)))
		exit(1);
	while (++j != i)
		str[j] = s1[j];
	str[j] = ' ';
	while (++j < i + x + 2)
		str[j] = s2[++k];
	str[j] = '\0';
	return (str);
}

char			*ft_strcat3(char *s1, char *s2)
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
	if (!(str = ft_xalloc((sizeof(char) * i + x + 4), 0)))
		exit(1);
	while (++j != i)
		str[j] = s1[j];
	str[j] = ',';
	str[++j] = ' ';
	while (++j < i + x + 2)
		str[j] = s2[++k];
	str[j] = '\0';
	return (str);
}
