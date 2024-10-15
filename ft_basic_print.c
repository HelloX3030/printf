/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:08:39 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/15 17:30:20 by lseeger          ###   ########.fr       */
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

static int	print_p_helper(unsigned int n)
{
	int	len;

	if (n <= 16)
		write(1, &"0123456789ABCDEFG"[n], 1);
	else
	{
		len += print_p_helper(n / 10);
		write(1, &"0123456789"[n % 10], 1);
		return (len);
	}
}

int	ft_print_p(va_list args)
{
	unsigned int	n;

	n = va_arg(args, void *);
	return (print_p_helper(n);)
}

int	ft_print_d(va_list args)
{
}
