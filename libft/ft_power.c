/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:51:02 by tblaudez          #+#    #+#             */
/*   Updated: 2018/07/28 16:57:03 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_power(intmax_t nbr, int power)
{
	if (power <= 0)
		return (!power ? 1 : 0);
	if (power > 0)
		nbr *= ft_power(nbr, --power);
	return (nbr);
}
