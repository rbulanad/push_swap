/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:54:42 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/15 12:55:07 by rbulanad         ###   ########.fr       */
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
