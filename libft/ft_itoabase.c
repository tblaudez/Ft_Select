/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:07:47 by tblaudez          #+#    #+#             */
/*   Updated: 2018/08/30 16:56:39 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoabase(intmax_t nbr, int base)
{
	char	*str;
	int		neg;
	int		i;

	if (base == 10)
		return (ft_itoa(nbr));
	neg = (nbr < 0 ? 1 : 0);
	nbr = (nbr < 0 ? -nbr : nbr);
	i = ft_nbrdig(nbr, base);
	str = ft_strnew(i);
	while (i-- > 0)
	{
		str[i] = (nbr % base) + (nbr % base > 9 ? 'a' - 10 : '0');
		nbr /= base;
	}
	return (neg ? ft_strjoinfree("-", str, 0, 1) : str);
}
