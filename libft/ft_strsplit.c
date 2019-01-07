/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:09:18 by tblaudez          #+#    #+#             */
/*   Updated: 2018/07/28 16:48:21 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_countwrd(const char *s, char c)
{
	int wrd;
	int	i;

	wrd = (*s != c ? 1 : 0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			wrd++;
		i++;
	}
	return (wrd);
}

char		**ft_strsplit(const char *s, char c)
{
	int		beg;
	int		end;
	int		i;
	int		j;
	char	**tab;

	if (!s || ft_strequ(s, "") || !(tab = ft_strarray_new(ft_countwrd(s, c))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		beg = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		if (end > beg)
			tab[j++] = ft_strsub(s, beg, end - beg);
	}
	return (tab);
}
