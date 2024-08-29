/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < libft.h >                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <malloc.h>
# include <stdbool.h>
# include <unistd.h>

typedef unsigned char	t_byte;

int					ft_atoi(const char *str);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_itoa(int n);

char				*ft_strdup(char *src);
unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int		ft_strlcat(char *dst, char *src, unsigned int n);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *s, const char *to_find, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

void				*ft_calloc(size_t count, size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, void *src, size_t s);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);

void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

void				ft_overflow(void);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, unsigned int n);
char				*ft_strcat(char *dst, char *src);
char				*ft_strncat(char *dst, const char *src, unsigned int n);
char				*ft_strstr(char *s, char *to_find);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnew(size_t size);
void				*ft_memccpy(void *dest, void *src, int c, size_t n);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif
