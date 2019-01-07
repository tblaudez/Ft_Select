/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:26:33 by tblaudez          #+#    #+#             */
/*   Updated: 2018/09/03 10:42:50 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarray_new(int len)
{
	char	**tab;

	if (!len)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (len + 1))))
		ft_exit("ft_strarray_new: malloc error.");
	while (len != -1)
	{
		tab[len] = NULL;
		len--;
	}
	return (tab);
}
