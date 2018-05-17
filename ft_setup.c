/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 08:44:10 by mguyout           #+#    #+#             */
/*   Updated: 2017/10/25 04:48:32 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "Libft/libft.h"

char				**ft_realloc(char **tab, char *path)
{
	int		i;
	int		x;
	char	**tmp;

	tmp = tab;
	i = -1;
	while (tab[++i])
		;
	x = 0;
	if (!(tab = ft_xalloc(sizeof(char*) * (i + 2), 0)))
		exit(1);
	if (!(tab[i] = ft_xalloc((sizeof(char) * ft_strlen(path) + 1), 0)))
		exit(1);
	while (x != i)
	{
		tab[x] = ft_strdup(tmp[x]);
		x++;
	}
	tab[i] = ft_strdup(path);
	tab[i + 1] = NULL;
	return (tab);
}

int					parsing(t_struct *env, char *argv, int x)
{
	if (argv[x] == '-' && argv[x + 1])
	{
		while (argv[++x])
		{
			if (argv[x] == 'a')
				env->a = 1;
			else if (argv[x] == 'R')
				env->r1 = 1;
			else if (argv[x] == 'r')
				env->r = 1;
			else if (argv[x] == 'l')
				env->l = 1;
			else if (argv[x] == 't')
				env->t = 1;
			else
			{
				miniprintf("Usage : ls [-Ralrt] [file ...]\n", argv[x]);
				exit(1);
			}
		}
		env->all = 1;
		return (1);
	}
	return (0);
}

int					padding(t_struct *env, int col)
{
	int	i;
	int	j;
	int	lock;
	int	x;

	lock = 0;
	x = 0;
	i = -1;
	while (env->tab5[++i])
	{
		j = -1;
		while (++j < ft_strlen(env->tab5[i]) && lock < col)
			if (env->tab5[i][j] == ' ')
				lock++;
		lock = 0;
		if (x < j)
			x = j;
	}
	return (x);
}

void				print2(t_struct *env, int swp, int j, int i)
{
	miniprintf("	");
	if (env->x < env->p4 - env->p3)
		while (env->x++ < env->p4 - env->p3)
			miniprintf(" ");
	swp = j;
	while (env->tab5[i][++swp] != ' ')
		;
	while (swp - j < env->p6 + 1 - env->p5)
	{
		miniprintf(" ");
		swp++;
	}
	while (env->tab5[i][++j])
		miniprintf("%c", env->tab5[i][j]);
	miniprintf(" ");
}

void				print(t_struct *env, int i)
{
	env->x1 = -1;
	env->swp1 = 0;
	env->j1 = -1;
	while (env->tab5[i][++env->j1] != ' ')
		miniprintf("%c", env->tab5[i][env->j1]);
	if (env->att == 0)
		miniprintf(" ");
	env->swp1 = env->j1;
	while (env->tab5[i][++env->swp1] != ' ')
		;
	while (++env->x1 < (env->p3 - (env->swp1)))
		miniprintf(" ");
	env->x1 = 0;
	while (env->tab5[i][++env->j1] != ' ')
		miniprintf("%c", env->tab5[i][env->j1]);
	miniprintf("%c", env->tab5[i][env->j1]);
	while (env->tab5[i][++env->j1] != ' ')
	{
		miniprintf("%c", env->tab5[i][env->j1]);
		env->x1++;
	}
	print3(env, i);
	print2(env, env->swp1, env->j1, i);
}
