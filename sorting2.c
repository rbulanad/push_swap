/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:53:06 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/15 15:54:19 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_big(t_stack *stack)
{
	t_node	*tmp;
	int		big;

	big = INT_MIN;
	tmp = stack->first;
	while (tmp)
	{
		if (tmp->actual > big)
			big = tmp->actual;
		tmp = tmp->next;
	}
	return (big);
}

int	find_small(t_stack *stack)
{
	t_node	*tmp;
	int		small;

	small = INT_MAX;
	tmp = stack->first;
	while (tmp)
	{
		if (tmp->actual < small)
			small = tmp->actual;
		tmp = tmp->next;
	}
	return (small);
}

int	in_chunk(t_stack *stack, int chunklen)
{
	t_node	*tmp;

	tmp = stack->first;
	while (tmp)
	{
		if (tmp->actual <= chunklen)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	look_top(t_stack *stack, int chunklen)
{
	t_node	*tmp;
	int		moves;

	moves = 0;
	tmp = stack->first;
	while (tmp)
	{
		if (tmp->actual <= chunklen)
			return (moves);
		tmp = tmp->next;
		moves++;
	}
	return (moves);
}

int	look_bot(t_stack *stack, int chunklen)
{
	t_node	*tmp;
	int		moves;

	moves = 0;
	tmp = stack->last;
	while (tmp)
	{
		if (tmp->actual <= chunklen)
			return (moves);
		tmp = tmp->previous;
		moves++;
	}
	return (moves);
}
