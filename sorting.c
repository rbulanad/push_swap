/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:41:49 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/15 17:45:56 by rbulanad         ###   ########.fr       */
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

	chunk = a->len / 5;
	nextchunk = find_small(a) + chunk;
	while (a->len > 0)
	{
		midchunk = (nextchunk) / 2;
		while (in_chunk(a, nextchunk) == 1)
		{
			if (look_top(a, nextchunk) < look_bot(a, nextchunk))
			{
				while (a->first->actual > nextchunk)
					ra_rb(a, 'a');
				if (a->first->actual < midchunk)
				{
					pa_pb(a, b, 'b');
					ra_rb(b, 'b');
				}
				else
					pa_pb(a, b, 'b');
			}
			else
			{
				while (a->first->actual > nextchunk) 
					rra_rrb(a, 'a');
				if (a->first->actual < midchunk)
				{
					pa_pb(a, b, 'b');
					ra_rb(b, 'b');
				}
				else
					pa_pb(a, b, 'b');
			}
		}
		nextchunk += absoluter(chunk);
	}
	while (b->len > 0)
	{
		if (look_top_big(b, find_big(b)) < look_bot_big(b, find_big(b)))
		{
			while (b->first->actual != find_big(b))
				ra_rb(b, 'b');
			pa_pb(a, b, 'a');
		}
		else
		{
			while (b->first->actual != find_big(b)) 
				rra_rrb(b, 'b');
			pa_pb(a, b, 'a');
		}
	}
}

void	fivehundred(t_stack *a, t_stack *b)
{
	int		chunk;
	int		nextchunk;
	int		midchunk;

	chunk = a->len / 11;
	nextchunk = find_small(a) + chunk;
	while (a->len > 0)
	{
		midchunk = (nextchunk) / 2;
		while (in_chunk(a, nextchunk) == 1)
		{
			if (look_top(a, nextchunk) < look_bot(a, nextchunk))
			{
				while (a->first->actual > nextchunk)
					ra_rb(a, 'a');
				if (a->first->actual < midchunk)
				{
					pa_pb(a, b, 'b');
					ra_rb(b, 'b');
				}
				else
					pa_pb(a, b, 'b');
			}
			else
			{
				while (a->first->actual > nextchunk) 
					rra_rrb(a, 'a');
				if (a->first->actual < midchunk)
				{
					pa_pb(a, b, 'b');
					ra_rb(b, 'b');
				}
				else
					pa_pb(a, b, 'b');
			}
		}
		nextchunk += absoluter(chunk);
	}
	while (b->len > 0)
	{
		if (look_top_big(b, find_big(b)) < look_bot_big(b, find_big(b)))
		{
			while (b->first->actual != find_big(b))
				ra_rb(b, 'b');
			pa_pb(a, b, 'a');
		}
		else
		{
			while (b->first->actual != find_big(b)) 
				rra_rrb(b, 'b');
			pa_pb(a, b, 'a');
		}
	}
}
