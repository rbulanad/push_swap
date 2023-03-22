/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:44:52 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/20 16:52:03 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack *stack, char x)
{
	int	tmp;

	if (stack->first == NULL || stack->first->next == NULL)
		return ;
	tmp = stack->first->actual;
	stack->first->actual = stack->first->next->actual;
	stack->first->next->actual = tmp;
	if (x == 'a')
		write(1, "sa\n", 3);
	else if (x == 'b')
		write(1, "sb\n", 3);
}

void	ra_rb(t_stack *stack, char x)
{
	int	tmp;

	if (stack->first == NULL || stack->last == NULL)
		return ;
	tmp = stack->first->actual;
	addbot(stack, tmp);
	stack->len--;
	stack->first = stack->first->next;
	free(stack->first->previous);
	stack->first->previous = NULL;
	if (x == 'a')
		write(1, "ra\n", 3);
	else if (x == 'b')
		write(1, "rb\n", 3);
}

void	rra_rrb(t_stack *stack, char x)
{
	int	tmp;

	if (stack->last == NULL)
		return ;
	tmp = stack->last->actual;
	addtop(stack, tmp);
	stack->len--;
	stack->last = stack->last->previous;
	free(stack->last->next);
	stack->last->next = NULL;
	if (x == 'a')
		write(1, "rra\n", 4);
	else if (x == 'b')
		write(1, "rrb\n", 4);
}

void	pa_pb(t_stack *a, t_stack *b, char x)
{
	int	tmp;

	if (x == 'a')
	{
		tmp = b->first->actual;
		delnode(b, b->first);
		b->len--;
		addtop(a, tmp);
		write(1, "pa\n", 3);
	}
	else if (x == 'b')
	{
		tmp = a->first->actual;
		delnode(a, a->first);
		a->len--;
		addtop(b, tmp);
		write(1, "pb\n", 3);
	}
}
