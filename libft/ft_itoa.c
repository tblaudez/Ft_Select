/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:29:15 by tblaudez          #+#    #+#             */
/*   Updated: 2018/05/21 16:54:23 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(intmax_t nbr)
{
	char	*str;
	int		neg;
	int		i;

	neg = (nbr < 0 ? 1 : 0);
	nbr = ((nbr < 0) ? -nbr : nbr);
	i = ft_nbrdig(nbr, 10);
	str = ft_strnew(i);
	while (i-- > 0)
	{
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (neg ? ft_strjoinfree("-", str, 0, 1) : str);
}
