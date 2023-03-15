/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:52:48 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/09 12:35:29 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	sa_sb(a, 'x');
	sa_sb(b, 'x');
	write(1, "ss\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra_rb(a, 'x');
	ra_rb(b, 'x');
	write(1, "rr\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra_rrb(a, 'x');
	rra_rrb(b, 'x');
	write(1, "rr\n", 3);
}
