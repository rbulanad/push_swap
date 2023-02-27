/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:22:24 by rbulanad          #+#    #+#             */
/*   Updated: 2023/02/21 11:27:56 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	if (!s2 || !s1)
		return (NULL);
	ret = malloc ((len(s1) + len(s2) + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

char	*joinfree(char *s1, char *s2)
{
	char	*ret;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	ret = ft_strjoin(s1, s2);
	free(s1);
	return (ret);
}
