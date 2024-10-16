/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:41:34 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/15 17:26:33 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_next_specifier(const char *s)
{
	char	*dif;

	dif = ft_strchr(s, '%');
	if (dif == NULL)
		return (ft_strlen(s));
	else
		return (dif - s);
}

int	print_specifier(const char *s, va_list args)
{
	if (s[1] == 'c')
		return (ft_print_c(args));
	else if (s[1] == 's')
		return (ft_print_s(args));
	else if (s[1] == 'p')
		return (ft_print_p(args));
	else if (s[1] == 'd')
		return (ft_print_d(args));
	return (0);
}

int	print_l(const char *s, int l)
{
	write(1, s, l);
	return (l);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		dif;

	va_start(args, s);
	len = 0;
	while (*s)
	{
		dif = get_next_specifier(s);
		len += print_l(s, dif);
		s += dif;
		len += print_specifier(s, args);
		if (*s == '%')
			s += 2;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	ft_printf("%s: %s\n", "11111", "22222");
}
