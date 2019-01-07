/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:33:24 by tblaudez          #+#    #+#             */
/*   Updated: 2018/09/17 13:33:27 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/stat.h>

static	int	calculate_space(t_select *list)
{
	int	maxlen;
	int	line;
	int	row;

	line = 0;
	row = 0;
	maxlen = get_line_max_len(list);
	if (maxlen > get_term_size('w') || get_term_size('h') == 0)
		return (0);
	while (42)
	{
		list = list->next;
		if (++line == get_term_size('h'))
		{
			line = 0;
			row += maxlen + 1;
			maxlen = get_line_max_len(list->next);
			if (get_term_size('w') - row < maxlen)
				return (0);
		}
		if (list == get_list_select())
			return (1);
	}
}

static void	print_files(int line, int row, t_select *list)
{
	struct stat file_type;

	tputs(tgoto(tgetstr("cm", NULL), row, line), 1, &my_putchar);
	if (list->selected)
		ft_putstr_fd("\033[7m", STDERR_FILENO);
	if (list->active)
		ft_putstr_fd("\033[4m", STDERR_FILENO);
	lstat(list->name, &file_type);
	if (S_ISDIR(file_type.st_mode))
		ft_fprintf(STDERR_FILENO, "{bold}{cyan}");
	else if (S_ISLNK(file_type.st_mode))
		ft_fprintf(STDERR_FILENO, "{magenta}");
	else
		ft_fprintf(STDERR_FILENO, "{green}");
	ft_fprintf(STDERR_FILENO, "%s{eoc}", list->name);
}

void		display_files(void)
{
	t_select	*list;
	int			l_r[2];
	int			maxlen;

	ft_setintarray(l_r, 0, 2);
	list = get_list_select();
	maxlen = get_line_max_len(list);
	if (!calculate_space(list))
	{
		ft_fprintf(STDERR_FILENO, \
		"\e[10A\r(╯°□°）╯︵ ┻━┻\nTOO SMALL!!\nO\nO\n\nS\nM\nA\nL\nL");
		return ;
	}
	while (42)
	{
		print_files(l_r[0], l_r[1], list);
		if (++(l_r[0]) == get_term_size('h'))
		{
			l_r[0] = 0;
			l_r[1] += maxlen + 1;
			maxlen = get_line_max_len(list->next);
		}
		if ((list = list->next) == get_list_select())
			break ;
	}
}

static void	move_lateral(long buf, t_select *list)
{
	t_select	*tmp;
	int			i;

	i = get_term_size('h');
	tmp = list;
	if (buf == RIGHT_KEY && list == get_list_select())
	{
		list = list->next;
		i--;
	}
	while (i--)
	{
		if (list == get_list_select() && (tmp->active = 1))
			return ;
		list = (buf == RIGHT_KEY ? list->next : list->prev);
	}
	list->active = 1;
}

void		move(long buf)
{
	t_select	*list;

	if (buf != UP_KEY && buf != DOWN_KEY && buf != LEFT_KEY \
	&& buf != RIGHT_KEY)
		return ;
	list = get_list_select();
	while (list->active != 1)
		list = list->next;
	list->active = 0;
	if (buf == UP_KEY)
		list->prev->active = 1;
	else if (buf == DOWN_KEY)
		list->next->active = 1;
	else if (buf == LEFT_KEY || buf == RIGHT_KEY)
		move_lateral(buf, list);
}
