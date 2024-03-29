/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:53:59 by dsy               #+#    #+#             */
/*   Updated: 2019/12/02 21:20:17 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_convs{
	unsigned char	c;
	char			*s;
	void			*p;
	signed int		d;
	signed int		i;
	unsigned int	u;
	int				x;
}					t_convs;

int			i_conversion(va_list params, char type);
int			s_conversion(va_list params, char type);
int			x_conversion(va_list params);
int			p_conversion(va_list params);
int			ft_printf(const char *format, ...);
#endif
