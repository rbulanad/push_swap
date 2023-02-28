/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:44:52 by rbulanad          #+#    #+#             */
/*   Updated: 2023/02/28 17:28:28 by rbulanad         ###   ########.fr       */
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

void	ss(t_stack *a, t_stack *b)
{
	sa_sb(a, 'x');
	sa_sb(b, 'x');
	write(1, "ss\n", 3);
}

void	ra_rb(t_stack *stack, char x)
{
	int	tmp;

	if (stack->first == NULL || stack->last == NULL)
		return ;
	tmp = stack->first->actual;
	addback(stack, tmp);
	stack->len--;
	stack->first = stack->first->next;
	free(stack->first->previous);
	stack->first->previous = NULL;
	if (x == 'a')
		write(1, "ra\n", 3);
	else if (x == 'b')
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra_rb(a, 'x');
	ra_rb(b, 'x');
	write(1, "rr\n", 3);
}

void	rra_rrb(t_stack *stack, char x)
{
	int	tmp;

	if (stack->last == NULL)
		return ;
	tmp = stack->last->actual;
	addfront(stack, tmp);
	stack->len--;
	stack->last = stack->last->previous;
	free(stack->last->next);
	stack->last->next = NULL;
	if (x == 'a')
		write(1, "ra\n", 3);
	else if (x == 'b')
		write(1, "rb\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra_rrb(a, 'x');
	rra_rrb(b, 'x');
	write(1, "rr\n", 3);
}

void	pa_pb(t_stack *a, t_stack *b, char *x)
{
	int	tmp;

	if (x == "pa")
	{
		tmp = b->last->actual;
		b->last = b->last->previous;
		free(b->last->next);
		b->last->next = NULL;
		addback(a, tmp);
		write(1, "pa\n", 3);
	}
	else if (x == "pb")
	{
		tmp = a->last->actual;
		a->last = a->last->previous;
		free(a->last->next);
		a->last->next = NULL;
		addback(b, tmp);
		write(1, "pb\n", 3);
	}
}
