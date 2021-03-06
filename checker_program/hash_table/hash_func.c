/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:52:59 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/17 16:15:14 by iltafah          ###   ########.fr       */
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
		hashed_key += (key[i] * 31);
		i++;
	}
	return (hashed_key);
}
