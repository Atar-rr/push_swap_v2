/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 13:41:18 by mjosue            #+#    #+#             */
/*   Updated: 2019/10/25 22:09:46 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>

typedef struct			s_printf
{
	char				c;
	char				a;
	char				b;
	int					d;
	int					i;
	int					o;
	int					x;
	double				f;
	double				e;
	double				g;
	unsigned int		u;
	unsigned long		lu;
	long double			lf;
	long double			lf_f;
	long long			lli;
	unsigned long long	llu;
	short int			hi;
	unsigned short		hu;
	unsigned char		hhu;
	signed char			hhi;
	char				*s;
	unsigned long long	p;
	char				arg[30];
	char				*buff;
	char				width;
	size_t				zu;
	int					flag_pl;
	int					flag_min;
	int					flag_space;
	int					flag_sharp;
	int					flag_t;
	int					flag_w;
	int					flag_to4;
	int					flag_zero;
	int					flag_free;
}						t_printf;

typedef struct			s_list
{
	char				*content;
	char				**str;
	size_t				content_size;
	struct s_list		*next;

}						t_list;

typedef struct			s_data
{
	char				*buff;
	const char			*format;
	int					count;
	int					flag;
	int					i;
	int					j;
	int					h;
	size_t				index;
	int					ind;
	int					jnd;
	int					in;
	int					fd;
	int					ret;
	int					retur;
	char				*av;
	int					full;
	int					f_t;
	int					t[2];
	int					line_count;
	int					block_count;
	int					x;
	int					y;
	char				*tmp;
	va_list				*arg;
	t_list				*list;
	t_printf			*code;
	struct s_data		*next;
}						t_data;

int						ft_atoi(const char *str);
void					ft_bzero (void *dest, size_t num);
int						ft_isalnum (int c);
int						ft_isalpha(int c);
int						ft_isascii (int c);
int						ft_isdigit(int c);
int						ft_isprint (int c);
void					*ft_memccpy(void *dest, const void *src, int c,
		size_t num);
void					*ft_memchr (const void *arr, int c, size_t num);
void					*ft_memcpy(void *dest, const void *src, size_t num);
void					*ft_memmove(void *dest, const void *src, size_t num);
void					*ft_memset (void *dest, int c, size_t num);
char					*ft_strcat (char *dest, const char *src);
char					*ft_strchr (const char *str, int ch);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy (char *dest, const char *src);
char					*ft_strdup(const char *str);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlen (const char *str);
char					*ft_strncat (char *dest, const char *src, size_t n);
int						ft_strncmp(const char *str1, const char *str2,
		size_t n);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strnstr(const char *str1, const char *str2,
		size_t len);
char					*ft_strrchr(const char *str, int ch);
char					*ft_strstr(const char *str1, const char *str2);
int						ft_tolower (int c);
int						ft_toupper (int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, char(*f)(unsigned int,
		char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
		size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_free(char ***str);
char					**ft_double_array(char **src, size_t size_1,
		size_t size_2);
char					**ft_strsplit(char const *str, char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_print_list(t_list *list);
t_list					*ft_lstnew(void *content, size_t content_size,
		int size);
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list*elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_create_elem(void *content, size_t content_size);
void					ft_lstfree(t_list **alst);
int						ft_strichr(const char *str, int ch);
int						get_next_line(const int fd, char **line);
t_data					*ft_lstnew_data(int param);
void					ft_error(int ar, int fd);
int						ft_factorial(int nb);
int						ft_sqrt(int nb);
void					ft_display(char **map, int x, int y);
int						ft_strnchr(const char *str, int ch, int n);
char					*ft_strcat (char *dest, const char *src);
char					*ft_strchr (const char *str, int ch);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy (char *dest, const char *src);
char					*ft_strdup(const char *str);
size_t					ft_strlen (const char *str);
int						ft_strncmp(const char *str1,
		const char *str2, size_t n);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strstr(const char *str1, const char *str2);
char					*ft_strnew(size_t size);
char					*ft_strsub(char const *s,
		unsigned int start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_itoa(long long int n);
int						ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
t_list					*ft_lstnew(void *content,
		size_t content_size, int size);
int						ft_strichr(const char *str, int ch);
t_data					*ft_lstnew_data(int param);
void					ft_error(int ar, int fd);
char					*ft_digit(unsigned long long digit, int sys);
char					*ft_digit_cap(unsigned long long digit, int sys);
long double				ft_modul(long double lf);
char					*ft_itoa_u(unsigned long long int n);
int						ft_schet(long long int n);
char					*ft_strjoin_printf(char const *s1,
		char const *s2, t_data *d);
size_t					ft_count_word(char const *str, char c);
size_t					ft_len_word(const char *s, char c);
int						*ft_qsort(int *stack, int start, int end);
long long				ft_atoi_long_long(const char *str);
int						len_numer_arr(char **digits);

#endif
