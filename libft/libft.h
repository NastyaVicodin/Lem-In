/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:59:45 by alukyane          #+#    #+#             */
/*   Updated: 2017/10/24 16:59:47 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include <stdarg.h>
# define ABS(v) ((v) < 0 ? -(v) : (v))

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef	struct		s_printf
{
	int		res;
	int		curr;
	char	*flag;
	int		width;
	int		prec;
	char	*spec;
	char	type;
	int		dot;
	int		star;
}					t_printf;
typedef	struct		s_unichar
{
	int		*arr_ind;
	int		len;
	char	*new_s;
}					t_unichar;
typedef struct		s_op
{
	char			*buff;
	int				f_desu;
	struct s_op		*next;
}					t_op;
char				*ft_allupper(char *str, int len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *s, const char *find, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
long long int		ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl_fd(char const *str, int fd);
void				ft_putnbr_fd(int nb, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *tab, t_list *(*f)(t_list *elem));
int					ft_positive_power(int nb, int power);
int					ft_sqrt(int nb);
int					ft_is_prime(int nb);
char				*ft_strrev(char *str);
char				*ft_rot42(char *str, int deep);
char				*ft_derot42(char *str, int deep);
char				*ft_itoa(long long int n);
char				*ft_itoa_base(unsigned long long int value, int base);
char				*ft_itoa_u(unsigned long long int n);
void				ft_print_end(int i, int len, int tmp, char c);
void				ft_putnbr(long long int n);
void				ft_putnbr_u(unsigned long long int nb);
int					ft_get_data(const char *format, t_printf *var, va_list ap);
t_printf			*process(t_printf *var, const char *f, int c, va_list ap);
t_printf			*ft_output_d(t_printf *var, int len_orig, long long digit);
t_printf			*ft_print_d(t_printf *var, va_list ap);
t_printf			*ft_print_u(t_printf *var, va_list ap);
t_printf			*ft_check_pos_o(t_printf *var);
t_printf			*ft_align_o(t_printf *var, char *str, int len, int len_or);
t_printf			*ft_output_o(t_printf *var, char *str);
t_printf			*ft_print_o(t_printf *var, va_list ap);
t_printf			*ft_print_b(t_printf *var, va_list ap);
t_printf			*ft_pos_x(t_printf *var, char *str, int len, int len_orig);
int					out_x(t_printf *var, char *str, int len, int len_origin);
t_printf			*ft_print_x(t_printf *var, va_list ap);
int					ft_btod(char *str);
int					ft_count_bytes(int chr);
char				*ft_make_wchar(char *str, int l, int bytes);
t_printf			*ft_print_c_w(t_printf *var, va_list ap);
t_printf			*ft_print_c(const char *format, t_printf *var, va_list ap);
t_printf			*ft_print_s_s(t_printf *var, va_list ap);
t_printf			*ft_check_align_s(t_printf *var, char *str, int len_origin);
t_printf			*ft_print_s_w(t_printf *var, va_list ap);
t_printf			*ft_print_s(t_printf *var, va_list ap);
t_printf			*ft_print_nbr(t_printf *var, va_list ap);
t_printf			*ft_print_str(const char *form, t_printf *var, va_list ap);
int					ft_printf(const char *format, ...);
void				free_array(char **arr);
#endif
