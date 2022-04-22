/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:22:08 by wwang             #+#    #+#             */
/*   Updated: 2022/03/20 16:54:57 by wwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	check_var(char c, va_list *args, int *l, int *i)
{
	if (c == 's')
		ft_putstr_str(va_arg(*args, char *), l);
	else if (c == 'd' || c == 'i')
		ft_putnbr_d(va_arg(*args, int), l);
	else if (c == 'u')
		ft_uns(va_arg(*args, unsigned int), l);
	else if (c == 'x')
		ft_hex(va_arg(*args, unsigned int), l, 'x');
	else if (c == 'X')
		ft_hex(va_arg(*args, unsigned int), l, 'X');
	else if (c == 'p')
		ft_p(va_arg(*args, size_t), l);
	else if (c == 'c')
		ft_putchar_len(va_arg(*args, int), l);
	else if (c == '%')
		ft_putchar_len('%', l);
	else
		(*i)--;
}

int	ft_printf(const char	*string, ...)
{
	va_list	args;
	int		i;
	int		l;

	i = 0;
	l = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			check_var(string[i], &args, &l, &i);
			i++;
		}
		else
		{
			ft_putchar_len((char)string[i], &l);
			i++;
		}
	}
	va_end(args);
	return (l);
}
