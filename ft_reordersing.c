/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reordersing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 09:09:22 by mguyout           #+#    #+#             */
/*   Updated: 2017/10/25 03:09:49 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "Libft/libft.h"

char		**opt_r(t_struct *env, int max, int lock, char **tab)
{
	char	*swp;
	int		x;
	int		i;

	i = max - 1;
	x = 0;
	while (x < i && x != i)
	{
		swp = ft_strdup(tab[x]);
		tab[x] = ft_strdup(tab[i]);
		tab[i] = ft_strdup(swp);
		swp = ft_strdup(env->tab6[x]);
		env->tab6[x] = ft_strdup(env->tab6[i]);
		env->tab6[i] = ft_strdup(swp);
		if (env->l == 1 && lock == -1)
		{
			swp = ft_strdup(env->tab5[x]);
			env->tab5[x] = ft_strdup(env->tab5[i]);
			env->tab5[i] = ft_strdup(swp);
		}
		x++;
		i--;
	}
	return (tab);
}

char		**swp(t_struct *env, int i, int x, char **tab)
{
	env->swp = ft_strdup(tab[x]);
	tab[x] = ft_strdup(tab[i]);
	tab[i] = ft_strdup(env->swp);
	env->swp = ft_strdup(env->tab6[x]);
	env->tab6[x] = ft_strdup(env->tab6[i]);
	env->tab6[i] = ft_strdup(env->swp);
	if (env->lock <= 0 && env->l == 1)
	{
		env->swp = ft_strdup(env->tab5[x]);
		env->tab5[x] = ft_strdup(env->tab5[i]);
		env->tab5[i] = ft_strdup(env->swp);
	}
	if (env->lock <= 0 && env->t == 1)
	{
		env->swp2 = env->tab3[x];
		env->tab3[x] = env->tab3[i];
		env->tab3[i] = env->swp2;
	}
	else if (env->lock == 1)
	{
		env->swp2 = env->tab4[x];
		env->tab4[x] = env->tab4[i];
		env->tab4[i] = env->swp2;
	}
	return (tab);
}

int			r1(t_struct *env, int i, int j, char **tab)
{
	if (ft_strcmp(tab[i], tab[i + j]) > 0)
	{
		env->j = 0;
		return (1);
	}
	return (0);
}

int			r2(t_struct *env, int i, int j)
{
	if (env->tab4[i] < env->tab4[i + j])
	{
		env->j = 0;
		return (1);
	}
	return (0);
}

char		**reorder(char **tab, t_struct *env, int max, int lock)
{
	env->x2 = -1;
	while (++env->x2 < max)
	{
		env->i2 = env->x2;
		env->j2 = 0;
		while (env->i2 + env->j2 < max)
		{
			env->j = 1;
			if (lock <= 0 && env->t == 0 && r1(env, env->i2, env->j2, tab) == 1)
				env->i2 += env->j2;
			else if (lock == 1 && r2(env, env->i2, env->j2) == 1)
				env->i2 += env->j2;
			else if (env->t == 1 && lock <= 0 && r3(env, env->i2, env->j2) == 1)
				env->i2 += env->j2;
			if (env->j == 0)
				env->j2 = 0;
			env->j2++;
		}
		env->lock = lock;
		if (env->j2 != max && env->i2 != env->x2)
			tab = swp(env, env->i2, env->x2, tab);
	}
	if (env->r == 1)
		tab = opt_r(env, max, lock, tab);
	return (tab);
}
