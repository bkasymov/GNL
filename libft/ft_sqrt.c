/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:57:00 by dpenney           #+#    #+#             */
/*   Updated: 2019/09/24 10:57:25 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_sqrt(int n)
{
	int		i;

	i = 1;
	if (n == 0)
		return (0);
	while (i * i < n)
		i++;
	if ((n % i) == 0)
		return (i);
	return (0);
}