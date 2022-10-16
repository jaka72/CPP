/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_mains.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 11:33:09 by jmurovec      #+#    #+#                 */
/*   Updated: 2020/11/04 16:06:10 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MAINS_H
# define LIBFT_MAINS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

#define BLKB "\e[40m"
#define HYEL "\e[0;93m"
#define HGRN "\e[0;92m"
#define HWHT "\e[0;97m"

#define YEL   "\e[0;33m"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

/*
** THESE FUNCTIONS ARE BEING READ FROM ..includes/libft.h
*/
/*
void			*ft_memset(void *str, int c, size_t n);
void			*ft_bzero(void *str, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *str, char c);
char			*ft_strnstr(const char *hay, const char *needle, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isspace(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar_fd(int c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
*/
/*
** MAINS //////////////////////////////
*/
//int				main(void);
int				ft_isalpha_main(void);
int				ft_tolower_main(void);
int				ft_isalnum_main(void);
int				ft_isdigit_main(void);
int				ft_strjoin_main(void);
int				ft_strdup_main(void);
int				ft_memccpy_main(void);
int				ft_strlcat_main(void);
int				ft_strlcpy_main(void);
int				ft_memmove_main(void);
int				ft_memset_main(void);
int				ft_memchr_main(void);
int				ft_strncmp_main(void);
int				ft_split_main(void);
int				ft_strtrim_main(void);
int				ft_itoa_main(void);
int				ft_strlen_main(void);
int				ft_strchr_main(void);
int				ft_substr_main(void);
int				ft_atoi_main(void);
int				ft_strnstr_main(void);
int				ft_memcmp_main(void);
int				ft_strmapi_main(void);
int				ft_strrchr_main(void);
int				ft_memcpy_main(void);
int				ft_calloc_main(void);
#endif
