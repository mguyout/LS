/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 21:48:09 by mguyout           #+#    #+#             */
/*   Updated: 2017/10/25 04:46:30 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "Libft/libft.h"

void		recu6(t_struct *env)
{
	if (env->l == 1)
	{
		env->p2 = padding(env, 1);
		env->p3 = padding(env, 2);
		env->p4 = padding(env, 3);
		env->p5 = padding(env, 4);
		env->p6 = padding(env, 5);
	}
}

DIR			*recu1(char *name, t_struct *env)
{
	DIR			*dir;
	struct stat	sb;
	int			octa;

	if (ft_strcmp(name, ".") != 0 && env->r1 == 1)
		miniprintf("\033[31m%s:\n\033[0m", name);
	if (lstat(name, &sb) == -1)
	{
		perror("ls");
		exit(1);
	}
	octa = deci_to_octa(sb.st_mode);
	dir = opendir(name);
	if (ft_right(octa) == 0 || dir == NULL)
	{
		miniprintf("ls: Permission denied\n");
		return (0);
	}
	return (dir);
}

void		recu2(t_struct *env, char **tab, char *name, char **tab2)
{
	int		x;

	x = -1;
	while (tab[++x])
	{
		if (env->l == 1)
			print(env, x);
		miniprintf("%s%s\033[0m\n", env->tab6[x], tab[x]);
	}
	if (env->r1 == 1)
	{
		env->total = 0;
		x = -1;
		while (tab2[++x])
		{
			ft_putchar('\n');
			recursive(ft_strcat(name, tab2[x]), NULL, env);
		}
	}
}

char		**recu3(t_struct *env, char **tab2, int x, char **tab)
{
	if (env->r1 == 1)
	{
		if (env->t == 1)
			tab2 = reorder(tab2, env, x, 1);
		else
			tab2 = reorder(tab2, env, x, 0);
	}
	x = -1;
	if (env->l == 1 && tab[0] != NULL)
		miniprintf("total %d\n", env->total);
	return (tab2);
}

int			recursive(char *name, DIR *dir, t_struct *env)
{
	struct dirent	*data;
	char			**tab;
	char			**tab2;
	int				x;

	env->i3 = 0;
	x = 0;
	if ((dir = recu1(name, env)) == 0)
		return (0);
	while ((data = readdir(dir)) != NULL)
		x = recu8(env, x, name, data);
	closedir(dir);
	if (!(tab2 = ft_xalloc(sizeof(char*) * (x + 2), 0)))
		exit(1);
	tab = recu7(env, env->i3, x, NULL);
	tab2[x] = NULL;
	env->tname = name;
	tab2 = recu9(env, tab, tab2, data);
	tab = reorder(tab, env, env->i, -1);
	tab2 = recu3(env, tab2, x, tab);
	recu2(env, tab, name, tab2);
	return (0);
}
