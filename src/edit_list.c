/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:38:30 by tblaudez          #+#    #+#             */
/*   Updated: 2018/09/03 14:38:31 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	delete_arg(void)
{
	t_select	*list;

	tputs(tgetstr("cl", NULL), 1, &my_putchar);
	list = get_list_select();
	while (list->active != 1)
		list = list->next;
	if (list == get_list_select() && list->next != list)
	{
		list->name = list->next->name;
		list->selected = list->next->selected;
		list->active = 0;
		list = list->next;
	}
	else if (list == get_list_select() && list->next == list)
	{
		free(list);
		modif_term_conf(1);
		exit(EXIT_SUCCESS);
	}
	list->prev->next = list->next;
	list->next->prev = list->prev;
	list->next->active = 1;
	free(list);
}

void	select_arg(void)
{
	t_select	*list;

	list = get_list_select();
	while (list->active != 1)
		list = list->next;
	list->selected = !(list->selected);
	list->active = 0;
	list->next->active = 1;
}
