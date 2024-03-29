/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:45:23 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/29 14:01:11 by rbulanad         ###   ########.fr       */
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

void	addtop(t_stack *stack, int value)
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

void	addbot(t_stack *stack, int value)
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

t_stack	*create_stack(t_data *data, t_stack *stack)
{
	int	i;

	stack = stack_init(stack);
	i = 0;
	while (data->tabarg[i])
		addbot(stack, ft_atol(data->tabarg[i++]));
	return (stack);
}

void	freetab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

/*
void	print_stack(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->first;
	while (tmp)
	{
		printf("%d\n", tmp->actual);
		tmp = tmp->next;
	}
	printf("len = %d\n", stack->len);
}*/
