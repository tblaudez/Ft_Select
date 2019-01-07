/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_issomething.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:07:07 by tblaudez          #+#    #+#             */
/*   Updated: 2018/07/28 16:43:39 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_something(const char *str, int (*f)(int c))
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!f(str[i]))
			return (0);
		i++;
	}
	return (1);
}
