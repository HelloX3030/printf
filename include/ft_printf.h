/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:42:09 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/16 10:12:02 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_print_c(va_list args);
int	ft_print_s(va_list args);
int	ft_print_p(va_list args);
int	ft_print_d(va_list args);
int	ft_print_i(va_list args);
int	ft_print_u(va_list args);
int	ft_print_x(va_list args);
int	ft_print_xx(va_list args);
int	ft_print_per(void);

#endif
