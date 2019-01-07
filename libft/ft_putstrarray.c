/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:56:47 by tblaudez          #+#    #+#             */
/*   Updated: 2018/08/13 18:36:48 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrarray(char **array)
{
	int i;

	i = 0;
	if (array && array[i])
		while (array[i])
		{
			ft_putendl(array[i]);
			i++;
		}
}
