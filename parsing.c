/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 07:58:03 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/28 17:31:59 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//to handle '-' and '+' followd by a space
int	checktmp(char *tmp)
{
	int	i;

	i = 0;
	if (!tmp)
		return (2);
	while (tmp && tmp[i + 1] != '\0')
	{
		if ((tmp[i] == '-' && tmp[i + 1] == ' ')
			|| (tmp[i] == '+' && tmp[i + 1] == ' '))
			return (1);
		i++;
	}
	return (0);
}

int	check_num(char **argv, t_data *data)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	tmp = NULL;
	while (argv[i])
	{
		data->tabarg = ft_split(argv[i++], ' ');
		j = 0;
		while (data->tabarg[j])
		{
			tmp = joinfree(tmp, data->tabarg[j]);
			tmp = joinfree(tmp, " ");
			if (ft_atol(data->tabarg[j]) > INT_MAX
				|| ft_atol(data->tabarg[j]) < INT_MIN
				|| checktmp(tmp) == 1
				|| ft_atol(data->tabarg[j++]) == 3000000000)
				return (freetab(data->tabarg), free(tmp), 1); //freetab here for the if trigger
		}
		freetab(data->tabarg);
	}
	if (checktmp(tmp) == 2)
		return (free(tmp), 2);
	return (data->tabarg = ft_split(tmp, ' '), free(tmp), 0);
}

int	check_doubles(t_data *data)
{
	int		i;
	int		j;

	if (data->tabarg[0] && !data->tabarg[1])
		return (freetab(data->tabarg), 1);
	i = 0;
	while (data->tabarg[i])
	{
		j = i + 1;
		while (data->tabarg[j])
		{
			if (ft_atol(data->tabarg[i]) == ft_atol(data->tabarg[j++]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_sort(t_data *data)
{
	int	i;

	i = 0;
	while (data->tabarg[i])
		i++;
	data->tablen = i;
	i = 0;
	while (i < data->tablen - 1)
	{
		if (ft_atol(data->tabarg[i]) > ft_atol(data->tabarg[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	is_parsed(t_data *data, char **argv)
{
	if (check_num(argv, data) == 2)
		return (1);
	if (check_num(argv, data) == 1)
		return (write(1, "Error\n", 6), 1);
	if (check_doubles(data) == 1)
		return (write(1, "Error\n", 6), 1);
	if (check_sort(data) == 1)
		return (1);
	return (0);
}
