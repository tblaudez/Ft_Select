# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/21 20:22:25 by tblaudez          #+#    #+#              #
#    Updated: 2018/10/24 13:04:55 by tblaudez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MSG:= "\e[1;31mO\e[1;32mN\e[1;33mW\e[1;34mA\e[1;35mR\
\b\e[1;36mD\e[1;33mS \e[1;31mA\e[1;32mO\e[1;33mS\e[1;34mH\
\b\e[1;35mI\e[1;36mM\e[1;31mA \e[1;36m!\e[1;31m!\e[0m\n"

NAME:= ft_select
SRC:= src/ft_select.c src/list.c src/edit_list.c src/move_and_display.c src/utils.c
OBJ:= $(subst src/,objects/,$(SRC:.c=.o))
LIBFT:= libft/libft.a
FLAGS:= -Wall -Wextra -Werror -I includes/

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@printf "\n\e[1;35mCréation du binaire\e[0m - %-50s\n" $@
	@gcc $(FLAGS) $(LIBFT) $(OBJ) -o $(NAME) -ltermcap
	@printf $(MSG)

objects/%.o: src/%.c
	@printf "\e[1;31mCréation des .o\e[0m - %-50s\r" $@
	@mkdir -p objects/
	@gcc $(FLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft/

clean:
	@/bin/rm -rf objects/ && \
	make -C libft clean

fclean: clean
	@/bin/rm -f $(NAME) && \
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re