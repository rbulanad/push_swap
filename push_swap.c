/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:39:47 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/08 18:10:56 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (1);
	else
	{
		data = malloc(sizeof(t_data));
		if (is_parsed(data, argv) == 1)
			return (freetab(data->tabarg), free(data), 1);
		a = create_stack(data, a);
		b = stack_init(b);
		if (data->tablen < 2)
			return (freetab(data->tabarg), free(data), 1);
		if (data->tablen == 2 || data->tablen == 3)
			three(a);
		if (data->tablen > 3)
			five(a, b);
		printf("STACK A\n");
		print_stack(a);
		printf("STACK B\n");
		print_stack(b);
		freestack(a);
		freestack(b);
		return (freetab(data->tabarg), free(data), 0);
	}
}
