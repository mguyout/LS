/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 02:48:56 by mguyout           #+#    #+#             */
/*   Updated: 2017/10/25 04:11:27 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "Libft/libft.h"

int			r3(t_struct *env, int i, int j)
{
	if (env->tab3[i] < env->tab3[i + j])
	{
		env->j = 0;
		return (1);
	}
	return (0);
}

void		print3(t_struct *env, int i)
{
	if (env->x1 < env->p4 - env->p3)
		while (env->x1++ < env->p4 - env->p3)
			miniprintf(" ");
	miniprintf("%c", env->tab5[i][env->j1]);
	env->x1 = 0;
	while (env->tab5[i][++env->j1] != ' ')
	{
		miniprintf("%c", env->tab5[i][env->j1]);
		env->x1++;
	}
}
