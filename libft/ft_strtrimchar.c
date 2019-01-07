/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 16:11:43 by tblaudez          #+#    #+#             */
/*   Updated: 2018/08/16 16:18:27 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimchar(char *str, int c)
{
	int	i;

	while ((i = ft_charsrc(str, c)) >= 0)
		ft_strcpy(str + i, str + i + 1);
	return (str);
}
