/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:13:47 by luferna3          #+#    #+#             */
/*   Updated: 2025/05/06 06:41:01 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lst(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	free_split(char **result, int count)
{
	int	i;

	if (!result)
		return ;
	i = 0;
	while (i < count)
		free(result[i++]);
	free(result);
}

void	free_all(t_stack *stack_a, t_stack *stack_b, char **split,
			int count)
{
	if (stack_a)
		free_lst(stack_a);
	if (stack_b)
		free_lst(stack_b);
	if (split)
		free_split(split, count);
}
