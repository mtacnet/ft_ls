/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 12:17:37 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/19 17:08:30 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem			*push_name_sortime(t_elem *lst, char *name, struct stat stat)
{
	t_elem		*prev;
	t_elem		*element;
	t_elem		*head;

	element = NULL;
	element = init_element(element);
	element->name = ft_strnew(ft_strlen(name));
	element->name = ft_strcpy(element->name, name);
	element->f_stat = stat;
	head = lst;
	prev = NULL;
	if (is_empty(lst))
		return (element);
	while (lst && ((element->f_stat.st_mtimespec.tv_sec <
				lst->f_stat.st_mtimespec.tv_sec) ||
				((element->f_stat.st_mtimespec.tv_sec ==
				lst->f_stat.st_mtimespec.tv_sec) &&
				ft_strcmp(element->name, lst->name) > 0)))
		egalegal(&prev, &lst, &lst, &lst->next);
	if (prev)
		prev->next = element;
	else
		head = element;
	element->next = lst;
	return (head);
}

t_elem			*push_path_sortime(t_elem *lst, char *path, struct stat stat)
{
	t_elem		*prev;
	t_elem		*element;
	t_elem		*head;

	element = NULL;
	element = init_element(element);
	element->path = ft_strnew(ft_strlen(path));
	element->path = ft_strcpy(element->path, path);
	element->f_stat = stat;
	head = lst;
	prev = NULL;
	if (is_empty(lst))
		return (element);
	while (lst && ((element->f_stat.st_mtimespec.tv_sec <
				lst->f_stat.st_mtimespec.tv_sec) ||
				((element->f_stat.st_mtimespec.tv_sec ==
				lst->f_stat.st_mtimespec.tv_sec) &&
				ft_strcmp(element->path, lst->path) > 0)))
		egalegal(&prev, &lst, &lst, &lst->next);
	if (prev)
		prev->next = element;
	else
		head = element;
	element->next = lst;
	return (head);
}

t_elem			*push_infos_name(t_elem *lst, char *name, struct stat stat)
{
	t_elem		*element;
	t_elem		*head;
	t_elem		*prev;

	element = NULL;
	element = init_element(element);
	element->name = ft_strnew(ft_strlen(name));
	element->name = ft_strcpy(element->name, name);
	element->f_stat = stat;
	head = lst;
	prev = NULL;
	if (is_empty(lst))
		return (element);
	while (lst && ft_strcmp(element->name, lst->name) > 0)
	{
		prev = lst;
		lst = lst->next;
	}
	if (prev)
		prev->next = element;
	else
		head = element;
	element->next = lst;
	return (head);
}

t_elem			*push_infos_path(t_elem *lst, char *path, struct stat stat)
{
	t_elem		*element;
	t_elem		*head;
	t_elem		*prev;

	element = NULL;
	element = init_element(element);
	element->path = ft_strnew(ft_strlen(path));
	element->path = ft_strcpy(element->path, path);
	element->f_stat = stat;
	head = lst;
	prev = NULL;
	if (is_empty(lst))
		return (element);
	while (lst && ft_strcmp(element->path, lst->path) > 0)
	{
		prev = lst;
		lst = lst->next;
	}
	if (prev)
		prev->next = element;
	else
		head = element;
	element->next = lst;
	return (head);
}

t_elem			*push_sort_path(t_elem *lst_dname, char *path)
{
	t_elem		*element;
	t_elem		*head;
	t_elem		*prev;

	element = NULL;
	element = init_element(element);
	element->path = ft_strnew(ft_strlen(path));
	element->path = ft_strcpy(element->path, path);
	head = lst_dname;
	prev = NULL;
	if (is_empty(lst_dname))
		return (element);
	while (lst_dname && ft_strcmp(element->path, lst_dname->path) > 0)
	{
		prev = lst_dname;
		lst_dname = lst_dname->next;
	}
	if (prev)
		prev->next = element;
	else
		head = element;
	element->next = lst_dname;
	return (head);
}
