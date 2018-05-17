/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 08:50:07 by mguyout           #+#    #+#             */
/*   Updated: 2017/10/25 04:51:39 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "Libft/libft.h"

char		**spe_case(char **tab, t_struct *env, char **argv, int i)
{
	int			lock;
	struct stat	sb;

	lock = 0;
	(i = (parsing(env, argv[1], 0) == 1 ? 1 : 0));
	while (argv[++i])
	{
		if (stat(argv[i], &sb) == -1)
			;
		else if (S_ISDIR(sb.st_mode))
			tab = ft_realloc(tab, argv[i]);
		else
		{
			lock = 1;
			miniprintf("%s\n", argv[i]);
		}
	}
	if (tab[0] != NULL && lock == 1)
		ft_putchar('\n');
	if (tab[0] == NULL && env->all == 0)
		exit(1);
	return (tab);
}

char		**check_dir(t_struct *env, char **argv)
{
	char		**tab;
	int			i;
	int			lock;
	struct stat	sb;

	i = 0;
	lock = 0;
	if (parsing(env, argv[1], lock) == 1)
		i = 1;
	if (!(tab = ft_xalloc(sizeof(char*) * 1, 0)))
		return (0);
	tab[0] = NULL;
	while (argv[++i])
	{
		if (stat(argv[i], &sb) == -1)
		{
			perror("ls");
			lock = 1;
		}
	}
	tab = spe_case(tab, env, argv, i);
	return (tab);
}

t_struct	*init(void)
{
	t_struct *env;

	if (!(env = ft_xalloc(sizeof(t_struct), 0)))
		exit(1);
	env->r1 = 0;
	env->x = 0;
	env->i = 0;
	env->r = 0;
	env->a = 0;
	env->t = 0;
	env->l = 0;
	env->all = 0;
	env->att = 0;
	env->total = 0;
	env->ln = 0;
	env->j = 1;
	env->p1 = 0;
	env->attr = 0;
	env->name = NULL;
	env->tab5 = NULL;
	env->tab2 = NULL;
	env->swp = NULL;
	env->swp2 = 0;
	return (env);
}

void		launch(t_struct *env, char **tab, int argc, char **argv)
{
	int i;

	i = -1;
	if (argc == 1)
	{
		recursive(".", NULL, env);
		exit(1);
	}
	tab = check_dir(env, argv);
	if (tab[0] == NULL && argc > 2)
		exit(1);
	if (env->all == 1 && argc == 2)
		recursive(".", NULL, env);
	else if (argc == 2)
		recursive(argv[1], NULL, env);
	else
	{
		while (tab[++i + 1] && tab[i])
		{
			recursive(tab[i], NULL, env);
			ft_putchar('\n');
		}
		recursive(tab[i], NULL, env);
	}
}

int			main(int argc, char **argv)
{
	int			i;
	t_struct	*env;

	i = -1;
	env = init();
	launch(env, NULL, argc, argv);
	ft_xclear(0);
	return (0);
}
