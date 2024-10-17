/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:08:21 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/17 10:27:34 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	ft_print_x_helper(unsigned int n)
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
		len += ft_print_x_helper(n / 16) + 1;
		write(FD, &"0123456789abcdef"[n % 16], 1);
		return (len);
	}
}

int	ft_print_x(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_print_x_helper(n));
}
