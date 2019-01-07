/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:30:32 by tblaudez          #+#    #+#             */
/*   Updated: 2018/08/30 17:33:33 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>

# include "ft_fprintf.h"
# include "get_next_line.h"

typedef	struct			s_list
{
	void				*content;
	int					content_size;
	struct s_list		*next;
}						t_list;

/*
** DISPLAY FUNCTIONS
*/
void					ft_putchar(char c);
void					ft_putstr(const char *s);
void					ft_putendl(const char *s);
void					ft_putnbr(intmax_t n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(const char *s, int fd);
void					ft_putendl_fd(const char *s, int fd);
void					ft_putnbr_fd(intmax_t n, int fd);
void					ft_putstrarray(char **array);
/*
** CHECK FUNCTIONS
*/
int						ft_isspace(int c);
int						ft_isupper(int c);
int						ft_islower(int c);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_str_is_something(const char *str, int (*f)(int c));
/*
** MEMORY FUNCTIONS
*/
void					*ft_memccpy(void *dst, const void *src,
						int c, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memset(void *s, int c, size_t n);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
void					ft_bzero(void *s, size_t n);
void					ft_setintarray(int *s, int c, size_t size);
/*
** STRING FUNCTIONS
*/
char					*ft_strcat(char *dst, const char *src);
char					*ft_strncat(char *dst, const char *src, size_t len);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strchr(char *s, int c);
char					*ft_strrchr(const char *s, int c);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strdup(const char *src);
char					*ft_strndup(const char *str, size_t n);
int						ft_strlen(const char *str);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
int						ft_strequ(const char *s1, const char *s2);
int						ft_strnequ(const char *s1, const char *s2, size_t n);
char					*ft_strsub(const char *s, int start, size_t len);
char					*ft_strjoinfree(char *s1, char *s2,
						int free1, int free2);
char					*ft_strtrim(char *s);
char					**ft_strsplit(const char *s, char c);
char					*ft_strreplace(char *str, int c, const char *s);
char					*ft_strreplace_all(char *str, int c, const char *s);
int						ft_charsrc(const char *str, char c);
int						ft_charnsrc(const char *str, char c, size_t n);
int						ft_charrsrc(const char *str, char c);
char					*ft_strtrimchar(char *str, int c);
/*
** T_LIST FUNCTIONS
*/
t_list					*ft_lstget(void);
t_list					*ft_lstnew(void *content, int content_size);
void					ft_lstadd(t_list **head_ref, t_list *new);
size_t					ft_lstlen(t_list *list);
/*
** NUMBERS RELATED FUNCTIONS
*/
char					*ft_itoa(intmax_t n);
char					*ft_itoabase(intmax_t n, int base);
int						ft_atoi(const char *str);
int						ft_atoibase(const char *str, int base);
int						ft_nbrdig(intmax_t n, int base);
intmax_t				ft_power(intmax_t nbr, int pow);
/*
** STRING ARRAY RELATED FUNCTIONS
*/
char					**ft_strarray_new(int len);
void					ft_strarray_del(char **array);
size_t					ft_strarraylen(char **array);
/*
** MISC
*/
int						get_next_line(int fd, char **line);
void					ft_exit(const char *msg);

#endif
