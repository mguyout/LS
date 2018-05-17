/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnmath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 06:59:57 by mguyout           #+#    #+#             */
/*   Updated: 2017/10/25 02:07:14 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "Libft/libft.h"

void		miniprintf(char *str, ...)
{
	va_list	ap;
	int		i;

	i = -1;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] == '%')
				ft_putchar('%');
			else if (str[i + 1] == 's')
				ft_putstr(va_arg(ap, char *));
			else if (str[i + 1] == 'd')
				ft_putnbr(va_arg(ap, int));
			else if (str[i + 1] == 'c')
				ft_putchar(va_arg(ap, int));
			if (str[++i + 1] && str[i] == '\\' && str[i + 1] == 'n')
				ft_putchar('\n');
		}
		else
			ft_putchar(str[i]);
	}
	va_end(ap);
}

void		color(t_struct *env, struct stat sb, int i)
{
	if (!(env->tab6[i] = ft_xalloc(sizeof(char*) * 20, 0)))
		exit(1);
	if (S_ISDIR(sb.st_mode))
		env->tab6[i] = ft_strdup("\033[36;1m");
	else if (S_ISREG(sb.st_mode))
		env->tab6[i] = ft_strdup("");
	else if (S_ISCHR(sb.st_mode))
		env->tab6[i] = ft_strdup("\033[43;34m");
	else if (S_ISBLK(sb.st_mode))
		env->tab6[i] = ft_strdup("\033[46;34m");
	else if (S_ISFIFO(sb.st_mode))
		env->tab6[i] = ft_strdup("\033[1;33m");
	else if (S_ISSOCK(sb.st_mode))
		env->tab6[i] = ft_strdup("\033[1;32m");
	else if (S_ISLNK(sb.st_mode))
		env->tab6[i] = ft_strdup("\033[1;35m");
}

int			ft_right(int octa)
{
	char	*str;

	str = ft_itoa(octa);
	if (str[2] < '4')
		return (0);
	return (1);
}

int			deci_to_octa(int deci)
{
	int		octa;
	int		i;

	octa = 0;
	i = 1;
	while (deci != 0)
	{
		octa += (deci % 8) * i;
		deci /= 8;
		i *= 10;
	}
	return (octa);
}
