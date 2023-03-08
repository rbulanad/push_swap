/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:19:35 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/01 12:39:52 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	long	result;
	long	signe;

	result = 0;
	i = 0;
	signe = 1;
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
		result += (str[i] - 48);
		i++;
	}
	if (str[i] != '\0')
		return (3000000000);
	return (result * signe);
}
/*
int main(void)
{
	char str[] = "12 3";
	char str2[] = "12 3";
	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str2));
}*/
