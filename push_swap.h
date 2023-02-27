/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:46:58 by rbulanad          #+#    #+#             */
/*   Updated: 2023/02/27 16:05:18 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_data
{
	char	**tabarg;
	int		tablen;
}				t_data;

typedef struct s_node
{
	int		actual;
	struct s_node	*next;
	struct s_node	*previous;
}				t_node;

typedef struct s_stack
{
	int		len;
	struct s_node	*first;
	struct s_node	*last;
}				t_stack;

long	ft_atol(char *str);
int		len(char *s);
char	*substr2(char *s, int start, int end);
char	**ft_split(char *s, char c);
char	*joinfree(char *s1, char *s2);
int		is_parsed(t_data *data, char **argv);
void	freetab(char **tab);
void	create_stacks(t_data *data, t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);

#endif