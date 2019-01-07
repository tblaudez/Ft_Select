/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:13:09 by tblaudez          #+#    #+#             */
/*   Updated: 2018/09/17 13:13:10 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_term_size(char w_h)
{
	struct winsize w;

	ioctl(STDERR_FILENO, TIOCGWINSZ, &w);
	if (w_h == 'w')
		return (w.ws_col);
	else
		return (w.ws_row);
}

int		get_line_max_len(t_select *list)
{
	int			tmp;
	int			ret;
	int			i;

	i = get_term_size('h');
	ret = 0;
	while (i--)
	{
		tmp = ft_strlen(list->name);
		if (tmp > ret)
			ret = tmp;
		list = list->next;
	}
	return (ret);
}

void	print_selection(void)
{
	t_select	*list;
	int			i;

	modif_term_conf(1);
	list = get_list_select();
	i = 0;
	while (42)
	{
		if (list->selected == 1 && !(i++))
			ft_fprintf(STDOUT_FILENO, "%s", list->name);
		else if (list->selected == 1 && i > 0)
			ft_fprintf(STDOUT_FILENO, " %s", list->name);
		if ((list = list->next) == get_list_select())
			break ;
	}
	free_list();
	exit(EXIT_SUCCESS);
}

void	modif_term_conf(int type)
{
	struct termios			term;
	static struct termios	initial_conf;

	if (type == 1)
	{
		tcsetattr(STDERR_FILENO, TCSANOW, &initial_conf);
		tputs(tgetstr("ve", NULL), 1, &my_putchar);
		tputs(tgetstr("te", NULL), 1, &my_putchar);
		return ;
	}
	if (!isatty(STDERR_FILENO))
		ft_exit("Not a terminal.");
	if (tgetent(NULL, getenv("TERM")) <= 0)
		ft_exit("Terminal not found in database.");
	if (!tgetstr("cm", NULL) || !tgetstr("cl", NULL) || !tgetstr("ve", NULL) \
	|| !tgetstr("te", NULL) || !tgetstr("vi", NULL) || !tgetstr("ti", NULL))
		ft_exit("Terminal lacks some capacities. Use another.");
	tcgetattr(STDERR_FILENO, &term);
	initial_conf = term;
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	tcsetattr(STDERR_FILENO, TCSANOW, &term);
	tputs(tgetstr("vi", NULL), 1, &my_putchar);
	tputs(tgetstr("ti", NULL), 1, &my_putchar);
	init_signal();
}
