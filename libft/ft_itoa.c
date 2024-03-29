/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 22:19:25 by dpenney           #+#    #+#             */
/*   Updated: 2019/10/04 00:05:24 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_sym(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static	int			ft_counter(int n)
{
	int		c;

	if (n <= 0)
		c = 1;
	else
		c = 0;
	while (n)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char				*ft_itoa(int n)
{
	int				len;
	char			*res;

	len = ft_counter(n);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(res, "-2147483648"));
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	res[len] = '\0';
	len--;
	while (n)
	{
		res[len] = ft_sym(n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (res);
}
