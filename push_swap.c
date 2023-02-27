/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:39:47 by rbulanad          #+#    #+#             */
/*   Updated: 2023/02/27 16:53:23 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_stack	*a;
	t_stack	*b;

	data = malloc(sizeof(t_data));
	if (is_parsed(data, argv) == 1)
		return (freetab(data->tabarg), free(data), 1);
	a = create_stack(data, a);
	b = stack_init(b);
	print_stack(a);
	print_stack(b);
	return (freetab(data->tabarg), free(data), 0);
}
