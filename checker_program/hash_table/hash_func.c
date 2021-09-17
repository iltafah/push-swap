/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:52:59 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/16 14:51:23 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hash_table.h"

int	hash_func(char *key)
{
	int	i;
	int	hashed_key;

	i = 0;
	hashed_key = 0;
	while (key[i] != '\0')
	{
		hashed_key += (key[i] * i);
		i++;
	}
	return (hashed_key);
}
