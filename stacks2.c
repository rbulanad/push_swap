/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:47:56 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/08 18:08:51 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delnode(t_stack *stack, t_node *node)
{
	if (!node->next && !node->previous)
	{
		stack->first = NULL;
		stack->last = NULL;
		free(node);
	}
	else if (!node->next)
	{
		stack->last = stack->last->previous;
		stack->last->next = NULL;
		free(node);
	}
	else if (!node->previous)
	{
		stack->first = stack->first->next;
		stack->first->previous = NULL;
		free(node);
	}
	else
	{
		node->previous->next = node->next;
		node->next->previous = node->previous;
		free(node);
	}
}

void	freestack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->first;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

void	mintop(t_stack *stack, t_node *tmp)
{
	int	num;
	int	numidx;

	num = 2147483647;
	tmp = stack->first;
	while (tmp)
	{
		tmp->position += 1;
		if (tmp->actual < num)
		{
			numidx = tmp->position;
			num = tmp->actual;
		}
		tmp = tmp->next;
	}
	if (numidx > (stack->len / 2))
	{
		while (stack->first->actual != num)
			rra_rrb(stack, 'a');
	}
	else
	{
		while (stack->first->actual != num)
			ra_rb(stack, 'a');
	}
}
