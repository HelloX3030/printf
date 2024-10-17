/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:41:22 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/17 10:24:59 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	ft_print_long_hex_helper(uintptr_t n)
{
	int	len;

	len = 0;
	if (n < 16)
	{
		write(FD, &"0123456789abcdef"[n], 1);
		return (len + 1);
	}
	else
	{
		len += ft_print_long_hex_helper(n / 16) + 1;
		write(FD, &"0123456789abcdef"[n % 16], 1);
		return (len);
	}
}

static int	ft_print_long_hex(uintptr_t n)
{
	write(FD, "0x", 2);
	return (ft_print_long_hex_helper(n) + 2);
}

int	ft_print_p(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	return (ft_print_long_hex((uintptr_t)ptr));
}
