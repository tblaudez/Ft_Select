/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:02:42 by tblaudez          #+#    #+#             */
/*   Updated: 2018/04/04 15:02:43 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void		*tmp;
	char		*dst_dup;
	const char	*src_dup;
	size_t		i;

	i = 0;
	dst_dup = dst;
	src_dup = src;
	tmp = dst;
	while (i < n)
	{
		dst_dup[i] = src_dup[i];
		i++;
	}
	return (tmp);
}
