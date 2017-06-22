/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:27:47 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/19 17:09:23 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./libft/libft.h"

typedef struct			s_env
{
	DIR					*dir_path;
	struct group		*f_grp;
	struct passwd		*f_pwd;
	char				*path;
	int					nb_blocks;
	int					nb_arg;
	int					s_major;
	int					s_minor;
	int					s_rights;
	int					s_links;
	int					s_owner;
	int					s_grp;
	int					s_size;
}						t_env;

typedef struct			s_flags
{
	char				*init_dir;
	int					l_flag;
	int					br_flag;
	int					a_flag;
	int					r_flag;
	int					t_flag;
	int					view_path;
	int					ret;
	int					index;
}						t_flags;

typedef struct			s_lst
{
	int					value;
	char				*path;
	char				*name;
	struct stat			f_stat;
	struct s_lst		*content;
	struct s_lst		*next;
}						t_elem;

typedef struct			s_norme
{
	int					major;
	int					minor;
	int					padding;
	int					ret;
}						t_norme;

/*
 ** LIST
*/

t_elem					*new_list(void);
t_elem					*init_element(t_elem *element);
t_elem					*push_path_sortime(t_elem *lst, char *path,
		struct stat stat);
t_elem					*push_name_sortime(t_elem *lst, char *name,
		struct stat stat);
t_elem					*push_path_sortime(t_elem *lst, char *path,
		struct stat stat);
t_elem					*push_sort_name(t_elem *lst, char *name);
t_elem					*push_infos_name(t_elem *lst, char *name,
		struct stat stat);
t_elem					*push_sort_path(t_elem *lst, char *path);
t_elem					*push_infos_path(t_elem *lst, char *path,
		struct stat stat);
t_elem					*reverse_lst(t_elem **lst, t_flags *flags);
int						is_empty(void *lst);
void					freelst(t_elem *lst);

/*
 ** MAIN FONCTIONS
*/

void					init_struct(t_flags *flags, t_env *env);
void					init_struct_env(t_env *env);
void					init_struct_norme(t_norme *norme);
void					ft_error(int ret, char bad_argv);
void					check_flags(t_flags *flags, char **argv);
void					prep_dir(char **argv, t_env *env, t_elem *elem,
		t_flags *flags);
void					print_lst_name(t_elem *lst, t_flags *flags, t_env *env);
void					print_reverse_list_name(t_elem *lst, t_flags *flags,
		t_env *env);
void					view_path_error(char *path);
void					view_list(t_elem *lst_file, t_elem *elem,
		t_flags *flags);
void					rec_dir(char *init_path, char *path, t_flags *flags);
void					process_path(char *path, t_flags *flags);
void					file_infos(t_elem *lst, t_env *env);
void					file_infos2(t_elem *lst, t_env *env);
void					treat_symlnk(char *name_ln, t_flags *flags,
		t_env *env, int ret);
void					display_total(t_elem *lst, t_flags *flags, t_env *env);
void					max_value(t_elem *lst, t_env *env);
void					max_value2(t_elem *lst, t_env *env);
void					max_value_size(t_elem *lst, t_env *env);
void					process_size(t_elem *lst, t_env *env);
void					process_space(int space);
int						getnbr(int nbr);

void					t_opt1(t_flags *flags, t_elem **lst_dname, char *dname,
		struct stat stat);
void					t_opt2(t_flags *flags, t_elem **lst_dir, char *dname,
		struct stat stat);
char					*concat_str(char *str, char *dname, t_env *env);
void					print(t_flags *flags, t_elem *lst_dname,
		t_elem *lst_dir, t_env *env);
void					process_env(t_env *env, char *path);
void					egalegal(t_elem **t1, t_elem **t2, t_elem **s1,
		t_elem **s2);
#endif
