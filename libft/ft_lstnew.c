/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:36:09 by tblaudez          #+#    #+#             */
/*   Updated: 2018/09/03 10:42:23 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, int content_size)
{
	t_list	*lst;

	if (!(lst = (t_list*)malloc(sizeof(t_list))))
		ft_exit("ft_lstnew: malloc error.");
	if (!content_size)
		lst->content = NULL;
	else
	{
		if (!(lst->content = (void*)malloc(content_size)))
			ft_exit("ft_lstnew: malloc error.");
		ft_memcpy(lst->content, content, content_size);
	}
	lst->content_size = content_size;
	lst->next = NULL;
	return (lst);
}
