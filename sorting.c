/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:41:49 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/17 16:13:46 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	tmp = NULL;
	while (a->len != 3)
	{
		mintop(a, tmp);
		pa_pb(a, b, 'b');
	}
	three(a);
	while (b->len != 0)
		pa_pb(a, b, 'a');
}

void	hundred(t_stack *a, t_stack *b)
{
	int		chunk;
	int		nextchunk;
	int		midchunk;

	chunk = (find_big(a) - find_small(a)) / 5;
	nextchunk = find_small(a) + chunk;
	while (a->len > 0)
	{
		midchunk = (nextchunk) / 2;
		while (in_chunk(a, nextchunk) == 1)
			sort_push_b(a, b, nextchunk, midchunk);
		nextchunk += chunk;
	}
	while (b->len > 0)
		sort_push_a(a, b);
}

void	fivehundred(t_stack *a, t_stack *b)
{
	int		chunk;
	int		nextchunk;
	int		midchunk;

	chunk = (find_big(a) - find_small(a)) / 11;
	nextchunk = find_small(a) + chunk;
	while (a->len > 0)
	{
		midchunk = (nextchunk) / 2;
		while (in_chunk(a, nextchunk) == 1)
			sort_push_b(a, b, nextchunk, midchunk);
		nextchunk += chunk;
	}
	while (b->len > 0)
		sort_push_a(a, b);
}
