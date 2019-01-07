# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 15:48:20 by tblaudez          #+#    #+#              #
#    Updated: 2018/09/18 10:55:15 by tblaudez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libft.a
SRC:= ft_atoi.c ft_memcpy.c ft_strncat.c ft_bzero.c ft_memmove.c ft_strncmp.c \
ft_isalnum.c ft_memset.c ft_strncpy.c ft_isalpha.c ft_strcat.c ft_strnstr.c \
ft_isascii.c ft_strchr.c ft_strrchr.c ft_isdigit.c ft_strcmp.c ft_strstr.c \
ft_isprint.c ft_strcpy.c ft_memccpy.c ft_strdup.c \
ft_memchr.c ft_strlcat.c ft_memcmp.c ft_strlen.c ft_memalloc.c ft_memdel.c \
ft_strnew.c ft_strdel.c ft_strclr.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strsplit.c \
ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstbackadd.c \
ft_isspace.c ft_str_is_something.c ft_islower.c ft_isupper.c ft_strndup.c \
ft_charsrc.c ft_charnsrc.c ft_nbrdig.c ft_atoibase.c \
ft_strreplace.c ft_power.c ft_strjoinfree.c ft_charrsrc.c ft_itoabase.c \
ft_strreplace_all.c ft_strarray_new.c ft_strarray_del.c \
ft_setintarray.c ft_strarraylen.c ft_putstrarray.c ft_lstlen.c ft_strtrim.c \
ft_strtrimchar.c ft_lstget.c get_next_line.c ft_exit.c ft_fprintf/ft_fprintf.c \
ft_fprintf/apply_flags.c ft_fprintf/get_alpha.c ft_fprintf/get_numeric.c \
ft_fprintf/utils.c ft_fprintf/custom_func.c
OBJ:= $(SRC:%.c=objects/%.o)
FLAGS:= -Wall -Wextra -Werror -I ../includes

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\n\e[1;33mCréation du binaire \e[0m- %s\n" $(NAME)
	@ar rc $(NAME) $(OBJ) \
	&& ranlib $(NAME)

objects/%.o: %.c
	@printf "\e[1;32mCréation des .o \e[0m- %-50s\r" $@
	@mkdir -p objects/ft_fprintf
	@gcc $(FLAGS) -c $< -o $@

clean:
	@/bin/rm -rf objects/

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re