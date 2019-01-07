/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:40:53 by tblaudez          #+#    #+#             */
/*   Updated: 2018/09/03 13:40:56 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select	*create_list_node(void)
{
	t_select	*list;

	if (!(list = (t_select*)malloc(sizeof(t_select))))
		ft_exit("ft_select: create_list_node: malloc error.");
	list->name = NULL;
	list->selected = 0;
	list->active = 0;
	list->prev = list;
	list->next = list;
	return (list);
}

t_select	*get_list_select(void)
{
	static t_select *list = NULL;

	if (!list)
		list = create_list_node();
	return (list);
}

void		init_list(char **argv)
{
	t_select	*list;

	list = get_list_select();
	list->active = 1;
	while (*argv)
	{
		list->name = *argv;
		if (*(++argv))
		{
			list->next = create_list_node();
			list->next->prev = list;
			list = list->next;
		}
	}
	list->next = get_list_select();
	get_list_select()->prev = list;
}

void		free_list(void)
{
	t_select	*list;
	t_select	*tmp;

	list = get_list_select();
	while (42)
	{
		tmp = list->next;
		free(list);
		list = tmp;
		if (tmp == get_list_select())
			break ;
	}
}
