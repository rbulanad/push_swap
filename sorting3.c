/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:54:42 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/17 17:35:46 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	look_top_big(t_stack *stack, int big)
{
	t_node	*tmp;
	int		moves;

	moves = 0;
	tmp = stack->first;
	while (tmp)
	{
		if (tmp->actual == big)
			return (moves);
		tmp = tmp->next;
		moves++;
	}
	return (moves);
}

int	look_bot_big(t_stack *stack, int big)
{
	t_node	*tmp;
	int		moves;

	moves = 0;
	tmp = stack->last;
	while (tmp)
	{
		if (tmp->actual == big)
			return (moves);
		tmp = tmp->previous;
		moves++;
	}
	return (moves);
}

int	absoluter(int num)
{
	if (num < 0)
		num *= (-1);
	return (num);
}

void	sort_push_b(t_stack *a, t_stack *b, int nextchunk, int midchunk)
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

void	sort_push_a(t_stack *a, t_stack *b)
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
