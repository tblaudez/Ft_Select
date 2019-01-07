/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:02:28 by tblaudez          #+#    #+#             */
/*   Updated: 2018/04/04 15:02:31 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_dup;

	s_dup = (unsigned char*)s;
	while (n--)
	{
		if (*s_dup == (unsigned char)c)
			return (s_dup);
		if (n)
			s_dup++;
	}
	return (NULL);
}
