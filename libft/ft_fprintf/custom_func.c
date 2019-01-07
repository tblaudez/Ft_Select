/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 10:07:52 by tblaudez          #+#    #+#             */
/*   Updated: 2018/09/03 10:07:54 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int		ft_unbrdig(uintmax_t nbr, int base)
{
	if (!nbr)
		return (0);
	return (1 + ft_unbrdig(nbr / base, base));
}

char	*ft_uitoabase(uintmax_t nbr, int base)
{
	char	*str;
	int		i;

	i = ft_unbrdig(nbr, base);
	str = ft_strnew(i);
	while (i-- > 0)
	{
		str[i] = (nbr % base) + (nbr % base > 9 ? 'a' - 10 : '0');
		nbr /= base;
	}
	return (str);
}
