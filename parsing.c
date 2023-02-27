/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 07:58:03 by rbulanad          #+#    #+#             */
/*   Updated: 2023/02/22 16:52:33 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
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
				|| ft_atol(data->tabarg[j++]) == 0)
				return (free(tmp), 1);
		}
		freetab(data->tabarg);
	}
	data->tabarg = ft_split(tmp, ' ');
	return (free(tmp), 0);
}

int	check_doubles(t_data *data)
{
	int		i;
	int		j;

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
	if (check_num(argv, data) == 1)
		return (write(1, "Error\n", 6), 1);
	if (check_doubles(data) == 1)
		return (write(1, "Error\n", 6), 1);
	if (check_sort(data) == 1)
		return (1);
	return (0);
}
