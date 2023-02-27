/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:45:23 by rbulanad          #+#    #+#             */
/*   Updated: 2023/02/27 16:38:20 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(t_stack *stack)
{
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->len = 0;
	stack->first = NULL;
	stack->last = NULL;
	return (stack);
}

void	addfront(t_stack *stack, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->actual = value;
	if (stack->first == NULL)
	{
		new->next = NULL;
		new->previous = NULL;
		stack->first = new;
		stack->last = new;
	}
	else
	{
		stack->first->previous = new;
		new->next = stack->first;
		stack->first = new;
		new->previous = NULL;
	}
	stack->len++;
}


void	addback(t_stack *stack, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->actual = value;
	if (stack->last == NULL)
	{
		new->next = NULL;
		new->previous = NULL;
		stack->first = new;
		stack->last = new;
	}
	else
	{
		stack->last->next = new;
		new->previous = stack->last;
		stack->last = new;
		new->next = NULL;
	}
	stack->len++;
}

void	create_stacks(t_data *data, t_stack *a, t_stack *b)
{
	int	i;

	a = stack_init(a);
	b = stack_init(b);
	i = 0;
	while (data->tabarg[i])
		addfront(a, ft_atol(data->tabarg[i++]));
	print_stack(a);
}

void	print_stack(t_stack *stack)
{
	t_node	*tmp;
	tmp = malloc(sizeof(t_node));
	tmp = stack->first;
	while (tmp)
	{
		printf("%d\n", tmp->actual);
		tmp = tmp->next;
	}
	printf("len = %d\n", stack->len);
}
