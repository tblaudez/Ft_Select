/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:33:12 by tblaudez          #+#    #+#             */
/*   Updated: 2018/08/06 18:52:03 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, int c, const char *s)
{
	int		i;
	char	*tmp;

	i = ft_charsrc(str, c);
	tmp = ft_strnew(ft_strlen(str) + ft_strlen(s));
	ft_strncpy(tmp, str, i);
	ft_strcat(tmp, s);
	ft_strcat(tmp, str + i + 1);
	ft_strdel(&str);
	return (tmp);
}
