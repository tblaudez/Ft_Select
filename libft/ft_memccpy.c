/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:02:19 by tblaudez          #+#    #+#             */
/*   Updated: 2018/04/04 15:02:20 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
	size_t n)
{
	size_t		i;
	char		*dst_dup;
	const char	*src_dup;

	i = 0;
	dst_dup = dst;
	src_dup = src;
	while (i < n)
	{
		dst_dup[i] = src_dup[i];
		if ((unsigned char)src_dup[i] == (unsigned char)c)
			return (dst_dup + i + 1);
		i++;
	}
	return (NULL);
}
