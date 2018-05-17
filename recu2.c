/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recu2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 04:30:22 by mguyout           #+#    #+#             */
/*   Updated: 2017/10/25 04:54:39 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "Libft/libft.h"

char		**recu4(struct stat sb, t_struct *env, char *name, char **tab)
{
	if (S_ISLNK(sb.st_mode) && env->l == 1)
	{
		if (!(env->buf = ft_xalloc((sizeof(char*) * sb.st_size + 2), 0)))
			exit(1);
		env->buf[0] = '\0';
		env->ln = readlink(ft_strcat(name, env->name),
				env->buf, sb.st_size + 1);
		env->buf[env->ln] = '\0';
		tab[env->i] = ft_strjoin(ft_strjoin(env->name, "\033[0m -> "),
				env->buf);
	}
	else
		tab[env->i] = ft_strdup(env->name);
	if (env->t == 1)
		env->tab3[env->i] = sb.st_mtime;
	color(env, sb, env->i);
	env->i++;
	return (tab);
}

char		**recu5(t_struct *env, char **tab, char **tab2, struct dirent *data)
{
	struct stat sb;

	if (lstat(ft_strcat(env->tname, env->name), &sb) == -1)
	{
		perror("ls");
		exit(1);
	}
	if (env->l == 1 && (env->name[0] != '.' || env->a == 1))
		opt_l(env, env->i, sb, ft_strcat(env->tname, env->name));
	if (data->d_type == 4 && env->r1 == 1 && ft_strcmp(env->name, ".") != 0
			&& ft_strcmp(env->name, "..") != 0)
	{
		tab2[env->x] = ft_strdup(env->name);
		if (env->t == 1)
			env->tab4[env->x] = sb.st_mtime;
		env->x++;
	}
	if (env->name[0] == '.' && env->a == 0)
		;
	else
		tab = recu4(sb, env, env->tname, tab);
	return (tab2);
}

char		**recu7(t_struct *env, int i, int x, char **tab)
{
	if (!(tab = ft_xalloc(sizeof(char*) * (i + 2), 0)))
		exit(1);
	if (!(env->tab6 = ft_xalloc(sizeof(char*) * (i + 2), 0)))
		exit(1);
	if (env->t == 1)
		if (!(env->tab3 = ft_xalloc((sizeof(unsigned long*) * i + 2), 0)))
			exit(1);
	if (env->r1 == 1 && env->t == 1)
		if (!(env->tab4 = ft_xalloc((sizeof(unsigned long*) * x + 2), 0)))
			exit(1);
	if (env->l == 1)
	{
		if (!(env->tab5 = ft_xalloc((sizeof(char*) * i + 2), 0)))
			exit(1);
		env->tab5[i] = NULL;
	}
	env->tab6[i] = NULL;
	tab[i] = NULL;
	env->x = 0;
	env->i = 0;
	return (tab);
}

int			recu8(t_struct *env, int x, char *name, struct dirent *data)
{
	struct stat sb;

	if (lstat(ft_strcat(name, data->d_name), &sb) == -1)
	{
		perror("ls");
		exit(1);
	}
	if (listxattr(ft_strcat(name, data->d_name), NULL, 0,
				XATTR_NOFOLLOW) > 0)
		env->p1 = 1;
	if (data->d_type == 4 && env->r1 == 1 &&
		ft_strcmp(data->d_name, ".") != 0 && ft_strcmp(data->d_name, "..") != 0)
		x++;
	if (data->d_name[0] == '.' && env->a == 0)
		;
	else
		env->i3++;
	return (x);
}

char		**recu9(t_struct *env, char **tab, char **tab2, struct dirent *data)
{
	DIR *dir;

	dir = opendir(env->tname);
	while ((data = readdir(dir)) != NULL)
	{
		env->name = ft_strdup(data->d_name);
		env->tname = ft_strdup(env->tname);
		tab2 = recu5(env, tab, tab2, data);
	}
	closedir(dir);
	return (tab2);
}
