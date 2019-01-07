/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charrsrc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:27:57 by tblaudez          #+#    #+#             */
/*   Updated: 2018/07/28 16:58:19 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charrsrc(const char *str, char c)
{
	int i;
	int ret;

	i = 0;
	ret = -1;
	if (str)
		while (str[i])
		{
			if (str[i] == c)
				ret = i;
			i++;
		}
	return (ret);
}
