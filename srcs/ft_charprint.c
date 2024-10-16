/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:08:39 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/16 09:40:23 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(va_list args)
{
	const char	c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

int	ft_print_s(va_list args)
{
	const char		*str = va_arg(args, char *);
	const size_t	len = ft_strlen(str);

	write(1, str, len);
	return (len);
}
