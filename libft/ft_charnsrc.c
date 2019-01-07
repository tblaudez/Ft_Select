/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charnsrc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:48:43 by tblaudez          #+#    #+#             */
/*   Updated: 2018/07/28 16:50:52 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charnsrc(const char *str, char c, size_t n)
{
	int i;

	i = 0;
	if (str)
		while (str[i] && n--)
		{
			if (str[i] == c)
				return (i);
			i++;
		}
	return (-1);
}
