/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:14:11 by dsy               #+#    #+#             */
/*   Updated: 2019/10/16 13:12:10 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void			*ft_memset(void *str, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
void			*ft_memccpy(void *str1, const void *str2, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void*s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strnstr(char const *haystack, const char *needle, size_t len);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t nitems, size_t size);
char			*ft_strdup(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
#endif
