/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 10:43:53 by mguyout           #+#    #+#             */
/*   Updated: 2017/10/25 04:48:18 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "Libft/libft.h"

void					opt1(t_struct *env, int i, struct stat sb, char *path)
{
	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		env->attr = 1;
	if (!(env->tab5[i] = ft_xalloc(sizeof(char*) *
		(11 + env->attr + env->p1), 0)))
		exit(1);
	if (S_ISDIR(sb.st_mode))
		env->tab5[i][0] = 'd';
	else if (S_ISREG(sb.st_mode))
		env->tab5[i][0] = '-';
	else if (S_ISCHR(sb.st_mode))
		env->tab5[i][0] = 'c';
	else if (S_ISBLK(sb.st_mode))
		env->tab5[i][0] = 'b';
	else if (S_ISFIFO(sb.st_mode))
		env->tab5[i][0] = 'p';
	else if (S_ISSOCK(sb.st_mode))
		env->tab5[i][0] = 's';
	else if (S_ISLNK(sb.st_mode))
		env->tab5[i][0] = 'l';
}

void					opt2(t_struct *env, int i, struct stat sb)
{
	(env->tab5[i][1] = (sb.st_mode & S_IRUSR) ? 'r' : '-');
	(env->tab5[i][2] = (sb.st_mode & S_IWUSR) ? 'w' : '-');
	(env->tab5[i][3] = (sb.st_mode & S_IXUSR) ? 'x' : '-');
	(env->tab5[i][4] = (sb.st_mode & S_IRGRP) ? 'r' : '-');
	(env->tab5[i][5] = (sb.st_mode & S_IWGRP) ? 'w' : '-');
	(env->tab5[i][6] = (sb.st_mode & S_IXGRP) ? 'x' : '-');
	(env->tab5[i][7] = (sb.st_mode & S_IROTH) ? 'r' : '-');
	(env->tab5[i][8] = (sb.st_mode & S_IWOTH) ? 'w' : '-');
	(env->tab5[i][9] = (sb.st_mode & S_IXOTH) ? 'x' : '-');
	if (env->attr == 1)
		env->tab5[i][10] = '@';
	else if (env->p1 == 1)
		env->tab5[i][10] = ' ';
	env->tab5[i][10 + env->p1] = '\0';
	if (env->tab5[i][10] == '@')
		env->att = 1;
	env->attr = 0;
	env->tab5[i] = ft_strcat2(env->tab5[i], ft_itoa(sb.st_nlink));
}

void					opt3(t_struct *env, int i, struct stat sb)
{
	if ((env->pwd = getpwuid(sb.st_uid)) != NULL)
		env->tab5[i] = ft_strcat2(env->tab5[i], env->pwd->pw_name);
	else
		env->tab5[i] = ft_strcat2(env->tab5[i], ft_itoa(sb.st_uid));
	if ((env->grp = getgrgid(sb.st_gid)) != NULL)
		env->tab5[i] = ft_strcat2(env->tab5[i], env->grp->gr_name);
	else
		env->tab5[i] = ft_strcat2(env->tab5[i], ft_itoa(sb.st_gid));
	if (S_ISBLK(sb.st_mode) || S_ISCHR(sb.st_mode))
	{
		env->tab5[i] = ft_strcat2(env->tab5[i], ft_itoa(major(sb.st_rdev)));
		env->tab5[i] = ft_strcat3(env->tab5[i], ft_itoa(minor(sb.st_rdev)));
	}
	else
		env->tab5[i] = ft_strcat2(env->tab5[i], ft_itoa(sb.st_size));
}

void					opt_l(t_struct *env, int i, struct stat sb, char *path)
{
	opt1(env, i, sb, path);
	opt2(env, i, sb);
	opt3(env, i, sb);
	if (sb.st_mtime + 15778800 > time(0))
		env->tab5[i] = ft_strcat2(env->tab5[i],
				ft_strsub(ctime(&sb.st_mtime), 4, 12));
	else
	{
		env->tab5[i] = ft_strcat2(env->tab5[i],
				ft_strsub(ctime(&sb.st_mtime), 4, 7));
		env->tab5[i] = ft_strcat2(env->tab5[i],
				ft_strsub(ctime(&sb.st_mtime), 20, 4));
	}
	if (env->name[0] != '.' || env->a == 1)
		if (!(S_ISDIR(sb.st_mode)))
			env->total = env->total + sb.st_blocks;
}
