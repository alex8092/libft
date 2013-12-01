/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:30:26 by amerle            #+#    #+#             */
/*   Updated: 2013/11/20 19:17:39 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# ifndef NULL
#  define NULL	0
# endif

enum e_bool { true = 1, false = 0 };
typedef enum e_bool	t_bool;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct 		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

/*	LIBC Functions */

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t dest_size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *str, const char *find);
char	*ft_strnstr(const char *str, const char *find, size_t n);
int		ft_atoi(char const *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

/* ########################### */

/* Additional functions */

void	ft_putchar(char c);
void	ft_putstr(char const *str);
void	ft_putnbr(int number);
void	ft_putunbr(unsigned int number);
void	ft_puthex(unsigned int number);
void	ft_putlnbr(long int number);
void	ft_putulnbr(unsigned long int number);
void	ft_putdouble(double number, t_bool use_preci, size_t precision);
void	ft_putlhex(unsigned long int number, t_bool lower);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
size_t	ft_itoa_ccount(unsigned long int n);
char	*ft_itoa(int n);
void	ft_putendl(char const *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* ########################### */

/* Lists functions */

t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/* ########################### */

/* Double chains lists functions */

t_dlist	*ft_dlistnew(void const *content, size_t content_size);
t_bool	ft_dlistadd(t_dlist **lst, t_dlist *item, t_bool top);
t_dlist	*ft_dlistcpy(t_dlist *src);
size_t	ft_dlistlen(t_dlist *lst);
t_bool	ft_dlistinsert(t_dlist **lst, t_dlist *item, size_t index);
t_bool	ft_dlistdel(t_dlist **item, t_bool next_replace);
t_bool	ft_dlistrm(t_dlist **lst, size_t index); /* NOT WORKING */
void	ft_dlistsort(t_dlist **lst, t_bool (*swap)(t_dlist *it, t_dlist *it2));
void	ft_dlistswap(t_dlist **item, t_dlist **item2);

/* ########################### */

void	ft_printf(char const *s, ...); /* NOT FINISHED */
t_bool	ft_isinarray(char c, char const *chars);
int		ft_indexinarray(char *str, char **tab, size_t tab_len);
char	*ft_regmatch(char *str, char *regex, size_t	*len_match);
t_bool	ft_reg_isinarray(char c, char *array);

#endif
