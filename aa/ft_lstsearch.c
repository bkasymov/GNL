/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 11:20:46 by dpenney           #+#    #+#             */
/*   Updated: 2019/10/03 20:05:02 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstsearch(t_list *alst, char *content)
{
	t_list		*curr;

	if (!alst || !content)
		return (NULL);
	curr = alst;
	while (curr->next != NULL)
	{
		if (curr->content == content)
			return (curr);
		else
			curr = curr->next;
	}
	return (NULL);
}
