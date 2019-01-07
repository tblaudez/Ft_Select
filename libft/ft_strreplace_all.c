/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:33:12 by tblaudez          #+#    #+#             */
/*   Updated: 2018/08/06 19:01:54 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace_all(char *str, int c, const char *s)
{
	while (ft_charsrc(str, c) >= 0)
		str = ft_strreplace(str, c, s);
	return (str);
}
