/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 17:45:08 by tblaudez          #+#    #+#             */
/*   Updated: 2018/09/25 11:04:07 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <term.h>
# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <signal.h>
# include "libft.h"

# define ENTER_KEY	10
# define ESC_KEY	27
# define SPC_KEY	32
# define BSP_KEY	127
# define LEFT_KEY	4479771
# define UP_KEY		4283163
# define RIGHT_KEY	4414235
# define DOWN_KEY	4348699
# define DEL_KEY	2117294875L

typedef struct		s_select
{
	char			*name;
	int				active;
	int				selected;
	struct s_select	*prev;
	struct s_select	*next;
}					t_select;

void				delete_arg(void);
void				select_arg(void);

t_select			*create_list_node(void);
t_select			*get_list_select(void);
void				init_list(char **argv);
void				free_list(void);

void				display_files(void);
void				move(long buf);

int					get_term_size(char w_h);
int					get_line_max_len(t_select *list);
void				print_selection(void);
int					my_putchar(int c);
void				modif_term_conf(int type);

void				signal_handler(int signo);
void				init_signal(void);

#endif
