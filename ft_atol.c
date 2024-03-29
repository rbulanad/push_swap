/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:19:35 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/29 11:43:53 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_whitespace(char c)
{
	if (c == 32 || c == 9)
		return (1);
	return (0);
}

long	ft_atol(char *str)
{
	int		i;
	long	result;
	long	signe;

	result = 0;
	i = 0;
	signe = 1;
	while (ft_whitespace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += (str[i++] - 48);
	}
	if (str[i] != '\0')
		return (3000000000);
	return (result * signe);
}
/*
#include <stdio.h>
int main(void)
{
	char str[] = "-12 ";
	printf("%ld\n", ft_atol(str));
}*/
