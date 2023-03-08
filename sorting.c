/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:41:49 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/08 18:10:58 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//top = a->first->actual
//middle = a->first->next->actual
//bottom = a->last->actual
void	three(t_stack *a)
{
	if (a->first->actual > a->first->next->actual
		&& a->first->next->actual < a->last->actual
		&& a->last->actual > a->first->actual)
		sa_sb(a, 'a');
	else if (a->first->actual > a->first->next->actual
		&& a->first->next->actual > a->last->actual
		&& a->last->actual < a->first->actual)
	{
		sa_sb(a, 'a');
		rra_rrb(a, 'a');
	}
	else if (a->first->actual > a->first->next->actual
		&& a->first->next->actual < a->last->actual
		&& a->last->actual < a->first->actual)
		ra_rb(a, 'a');
	else if (a->first->actual < a->first->next->actual
		&& a->first->next->actual > a->last->actual
		&& a->last->actual > a->first->actual)
	{
		sa_sb(a, 'a');
		ra_rb(a, 'a');
	}
	else if (a->last->actual < a->first->actual)
		rra_rrb(a, 'a');
}

void	five(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	while (a->len != 3)
	{
		mintop(a, tmp);
		pa_pb(a, b, 'b');
	}
	three(a);
	while (b->len != 0)
		pa_pb(a, b, 'a');
}
