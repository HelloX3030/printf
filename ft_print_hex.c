/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:46:11 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/16 14:16:58 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	ft_print_long_hex_helper(uintptr_t n)
{
	int	len;

	len = 0;
	if (n <= 16)
	{
		write(1, &"0123456789abcdef"[n], 1);
		return (1);
	}
	else
	{
		len += ft_print_long_hex_helper(n / 16);
		write(1, &"0123456789abcdef"[n % 16], 1);
		return (len);
	}
}

int	ft_print_long_hex(uintptr_t n)
{
	write(1, "0x", 2);
	return (ft_print_long_hex_helper(n));
}
