/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:39:47 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/01 12:15:26 by rbulanad         ###   ########.fr       */
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
	b = create_stack(data, b);
	printf("stack A\n");
	print_stack(a);
	printf("stack B\n");
	print_stack(b);
	ss(a, b);
	printf("stack A\n");
	print_stack(a);
	printf("stack B\n");
	print_stack(b);
	return (freetab(data->tabarg), free(data), 0);
}
