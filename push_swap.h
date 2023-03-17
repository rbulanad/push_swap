/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:46:58 by rbulanad          #+#    #+#             */
/*   Updated: 2023/03/17 16:17:02 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //////////////////////////to be deleted
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_data
{
	char	**tabarg;
	int		tablen;
}				t_data;

typedef struct s_node
{
	int				actual;
	int				position;
	struct s_node	*next;
	struct s_node	*previous;
}				t_node;

typedef struct s_stack
{
	int		len;
	t_node	*first;
	t_node	*last;
}				t_stack;

long	ft_atol(char *str);
int		len(char *s);
char	*substr2(char *s, int start, int end);
char	**ft_split(char *s, char c);
char	*joinfree(char *s1, char *s2);
int		is_parsed(t_data *data, char **argv);
void	freetab(char **tab);
//stack
t_stack	*stack_init(t_stack *stack);
t_stack	*create_stack(t_data *data, t_stack *stack);
void	print_stack(t_stack *stack);
void	delnode(t_stack *stack, t_node *node);
void	freestack(t_stack *stack);
void	mintop(t_stack *stack, t_node *tmp);
//adds to top of stack
void	addtop(t_stack *stack, int value);
//adds to bottom of stack
void	addbot(t_stack *stack, int value);
//instructions
void	sa_sb(t_stack *stack, char x);
void	ss(t_stack *a, t_stack *b);
void	ra_rb(t_stack *stack, char c);
void	rr(t_stack *a, t_stack *b);
void	rra_rrb(t_stack *stack, char x);
void	rrr(t_stack *a, t_stack *b);
void	pa_pb(t_stack *a, t_stack *b, char x);
//sorting
int		in_chunk(t_stack *stack, int chunklen);
int		look_top(t_stack *stack, int chunklen);
int		look_bot(t_stack *stack, int chunklen);
int		look_top_big(t_stack *stack, int big);
int		look_bot_big(t_stack *stack, int big);
int		find_big(t_stack *stack);
int		find_small(t_stack *stack);
int		absoluter(int num);
void	sort_push_b(t_stack *a, t_stack *b, int nextchunk, int midchunk);
void	sort_push_a(t_stack *a, t_stack *b);
void	three(t_stack *a);
void	five(t_stack *a, t_stack *b);
void	hundred(t_stack *a, t_stack *b);
void	fivehundred(t_stack *a, t_stack *b);

#endif
