/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:48:06 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/17 11:58:30 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(va_list args)
{
	const char	*str = va_arg(args, char *);
	size_t		len;
	ssize_t		result;

	if (str == NULL)
	{
		result = write(FD, "(null)", 6);
		return ((int)result);
	}
	else
	{
		len = ft_strlen(str);
		result = write(1, str, len);
		return ((int)result);
	}
}
