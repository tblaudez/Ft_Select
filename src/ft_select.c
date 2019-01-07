/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:28:59 by tblaudez          #+#    #+#             */
/*   Updated: 2018/09/03 13:29:00 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		my_putchar(int c)
{
	return (write(STDERR_FILENO, &c, 1));
}

void	signal_handler(int signo)
{
	if ((signo >= 1 && signo <= 15) || signo == 21 || signo == 22 \
	|| (signo >= 24 && signo <= 27))
	{
		modif_term_conf(1);
		free_list();
		exit(EXIT_FAILURE);
	}
	else if (signo == SIGWINCH)
	{
		tputs(tgetstr("cl", NULL), 1, &my_putchar);
		display_files();
	}
	else if (signo == SIGTSTP)
	{
		modif_term_conf(1);
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
	}
	else if (signo == SIGCONT)
	{
		modif_term_conf(0);
		display_files();
	}
}

void	init_signal(void)
{
	int	i;

	i = 1;
	while (i != 31)
		signal(i++, &signal_handler);
}

int		main(int ac, char **av)
{
	long buf;

	if (ac == 1)
		return (1);
	modif_term_conf(0);
	init_list(av + 1);
	while (42)
	{
		display_files();
		buf = 0;
		read(STDERR_FILENO, &buf, 8);
		if (buf == ESC_KEY)
			break ;
		else if (buf == BSP_KEY || buf == DEL_KEY)
			delete_arg();
		else if (buf == ENTER_KEY)
			print_selection();
		else if (buf == SPC_KEY)
			select_arg();
		else
			move(buf);
	}
	modif_term_conf(1);
	free_list();
	return (0);
}
