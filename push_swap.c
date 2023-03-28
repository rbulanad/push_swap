/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:39:47 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/28 17:33:51 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	data = malloc(sizeof(t_data));
	if (is_parsed(data, argv) == 1)
		return (free(data), 1);
	a = create_stack(data, a);
	b = stack_init(b);
	if (data->tablen < 2)
		return (freetab(data->tabarg), free(data), 1);
	if (data->tablen <= 5)
		five(a, b);
	else if (data->tablen > 5 && data->tablen <= 100)
		hundred(a, b);
	else
		fivehundred(a, b);
	freestack(a);
	freestack(b);
	return (freetab(data->tabarg), free(data), 0);
}
