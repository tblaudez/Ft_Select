/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:53:00 by tblaudez          #+#    #+#             */
/*   Updated: 2018/08/07 19:04:44 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			ft_strcpy(str + i, str + i + 1);
		while (str[i] && !ft_isspace(str[i]))
			i++;
		if (ft_str_is_something(str + i, &ft_isspace))
		{
			str[i] = '\0';
			return (str);
		}
		str[i++] = ' ';
	}
	return (str);
}
