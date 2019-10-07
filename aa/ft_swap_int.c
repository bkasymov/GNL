/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 07:57:43 by dpenney           #+#    #+#             */
/*   Updated: 2019/09/30 07:39:08 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_swap_int(int a, int b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
