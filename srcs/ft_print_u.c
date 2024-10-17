/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:02:29 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/17 10:05:56 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_u_helper(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 9)
	{
		write(FD, &"0123456789"[n], 1);
		return (++len);
	}
	else
	{
		len += ft_print_u_helper(n / 10);
		write(FD, &"0123456789"[n % 10], 1);
		return (++len);
	}
}

int	ft_print_u(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_print_u_helper(n));
}
