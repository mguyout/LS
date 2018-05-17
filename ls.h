/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 01:41:02 by mguyout           #+#    #+#             */
/*   Updated: 2017/10/25 04:54:13 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H
# include <dirent.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include "Libft/libft.h"
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/xattr.h>
# include <stdarg.h>

typedef struct		s_struct
{
	unsigned long	*tab3;
	unsigned long	*tab4;
	unsigned long	swp2;
	struct passwd	*pwd;
	struct group	*grp;
	struct stat		sb;
	struct dirent	*data;
	char			**tab2;
	char			**tab5;
	char			**tab6;
	char			*tname;
	char			*name;
	char			*swp;
	char			*buf;
	int				attr;
	int				ln;
	int				total;
	int				p1;
	int				p2;
	int				p3;
	int				p4;
	int				p5;
	int				p6;
	int				p7;
	int				att;
	int				r1;
	int				r;
	int				a;
	int				l;
	int				t;
	int				all;
	int				x;
	int				x1;
	int				swp1;
	int				j1;
	int				i;
	int				i3;
	DIR				*dir;
	int				x2;
	int				i2;
	int				j2;
	int				lock;
	int				j;
}					t_struct;

typedef	struct		s_xmap
{
	void			**map;
	int				flags;
	size_t			ptr;
	size_t			size;
}					t_xmap;

void				*ft_salloc(size_t size);
void				*ft_xalloc(size_t size, int ref);
void				*ft_xcalloc(size_t size, int ref);
void				ft_xclear(int ref);
t_xmap				*ft_xmap(int ref, int mode);
void				miniprintf(char *str, ...);
void				miniprintf2(char *str, int i);
void				color(t_struct *env, struct stat sb, int i);
int					ft_right(int octa);
int					deci_to_octa(int deci);
char				*ft_strcat2(char *s1, char *s2);
char				*ft_strcat3(char *s1, char *s2);
char				**ft_realloc(char **tab, char *path);
int					padding(t_struct *env, int col);
void				print(t_struct	*env, int col);
int					main(int argc, char **argv);
void				launch(t_struct *env, char **tab, int argc, char **argv);
t_struct			*init(void);
char				**check_dir(t_struct *env, char **argv);
char				**spe_case(char **tab, t_struct *env, char **argv, int i);
int					recursive(char *name, DIR *dir, t_struct *env);
DIR					*recu1(char *name, t_struct *env);
void				recu2(t_struct *env, char **tab, char *name, char **tab2);
char				**recu3(t_struct *env, char **tab2, int x, char **tab);
char				**recu4(struct stat sb, t_struct *env,
		char *name, char **tab);
char				**recu5(t_struct *env, char **tab,
		char **tab2, struct dirent *data);
char				**recu7(t_struct *env, int i, int x, char **tab);
int					recu8(t_struct *env, int x, char *name,
		struct dirent *data);
char				**recu9(t_struct *env, char **tab, char **tab2,
		struct dirent *data);
int					parsing(t_struct *env, char *argv, int x);
char				**swp(t_struct *env, int i, int x, char **tab);
char				**opt_r(t_struct *env, int max, int lock, char **tab);
void				opt_l(t_struct *env, int i, struct stat sb, char *path);
void				opt_1(t_struct *env, int i, struct stat sb, char *path);
void				opt_2(t_struct *env, int i, struct stat sb);
void				opt_3(t_struct *env, int i, struct stat sb);
char				**reorder(char **tab, t_struct *env, int max, int lock);
int					r3(t_struct *env, int i, int j);
void				print3(t_struct *env, int i);
#endif
