/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbackc                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:49:37 by tblaudez          #+#    #+#             */
/*   Updated: 2018/08/20 17:27:03 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_backadd(t_list **head_ref, t_list *new)
{
	t_list	*list;

	list = *head_ref;
	while (list->next)
		list = list->next;
	list->next = new;
}
