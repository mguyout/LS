/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 06:53:35 by mguyout           #+#    #+#             */
/*   Updated: 2017/10/22 09:49:35 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "Libft/libft.h"

void			*ft_salloc(size_t size)
{
	void	*ret;

	if (!(ret = malloc(size)))
		exit(1);
	return (ret);
}

static t_xmap	*new_xmap(void)
{
	t_xmap	*ret;

	ret = ft_salloc(sizeof(t_xmap));
	ret->map = ft_salloc(sizeof(void *) * 4094);
	ret->flags = 1;
	ret->size = 4094;
	ret->ptr = 0;
	return (ret);
}

static t_xmap	*extend_xmap(t_xmap *map)
{
	void	**new;

	if (!map)
		return (NULL);
	map->size *= 2;
	new = ft_salloc(sizeof(void *) * map->size);
	ft_memcpy(new, map->map, map->ptr * sizeof(void *));
	free(map->map);
	map->map = new;
	return (map);
}

static void		free_xmap(t_xmap *xmap)
{
	if (!xmap)
		return ;
	free(xmap->map);
	free(xmap);
}

t_xmap			*ft_xmap(int ref, int mode)
{
	static t_xmap	*maps[32];

	if (mode == 3)
	{
		free_xmap(maps[ref]);
		maps[ref] = NULL;
		return (NULL);
	}
	else if (mode == 2)
		return (extend_xmap(maps[ref]));
	if (!maps[ref])
		maps[ref] = new_xmap();
	return (maps[ref]);
}
