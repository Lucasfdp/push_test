/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:14:46 by luferna3          #+#    #+#             */
/*   Updated: 2025/05/06 06:28:14 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_nums(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = ((*stack_a)->value);
	second = (((*stack_a)->next)->value);
	third = (ft_lstlast_ps(*stack_a)->value);
	if (first > second && second > third)
	{
		rotate(stack_a, 'a', 1);
		swap(stack_a, 'a', 1);
	}
	if (first < second && second > third && first > third)
		reverse_rotate(stack_a, 'a', 1);
	if (first < second && second > third && first < third)
	{
		swap(stack_a, 'a', 1);
		rotate(stack_a, 'a', 1);
	}
	if (first > second && second < third && first < third)
		swap(stack_a, 'a', 1);
	if (first > second && second < third && first > third)
		rotate(stack_a, 'a', 1);
}

void	four_nums(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest;

	smallest = smallest_value(*stack_a);
	if (smallest == 0)
		push(stack_a, stack_b, 'b', 1);
	else if (smallest == 1)
	{
		swap(stack_a, 'a', 1);
		push(stack_a, stack_b, 'b', 1);
	}
	else if (smallest == 2)
	{
		rotate(stack_a, 'a', 1);
		rotate(stack_a, 'a', 1);
		push(stack_a, stack_b, 'b', 1);
	}
	else if (smallest == 3)
	{
		rotate(stack_a, 'a', 1);
		push(stack_a, stack_b, 'b', 1);
	}
	three_nums(stack_a);
	push(stack_b, stack_a, 'a', 1);
}

int	smallest_value(t_stack *stack_a)
{
	int	smallest;
	int	index;
	int	pos;

	index = 0;
	pos = 0;
	smallest = stack_a->value;
	while (stack_a)
	{
		if ((stack_a->value) < smallest)
		{
			smallest = stack_a->value;
			pos = index;
		}
		stack_a = stack_a->next;
		index++;
	}
	return (pos);
}

void	five_nums(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest;

	smallest = smallest_value(*stack_a);
	while (smallest--)
		rotate(stack_a, 'a', 1);
	push(stack_a, stack_b, 'b', 1);
	smallest = smallest_value(*stack_a);
	while (smallest--)
		rotate(stack_a, 'a', 1);
	push(stack_a, stack_b, 'b', 1);
	three_nums(stack_a);
	push(stack_b, stack_a, 'a', 1);
	push(stack_b, stack_a, 'a', 1);
}

void	six_nums(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest;

	smallest = smallest_value(*stack_a);
	while (smallest--)
		rotate(stack_a, 'a', 1);
	push(stack_a, stack_b, 'b', 1);
	smallest = smallest_value(*stack_a);
	while (smallest--)
		rotate(stack_a, 'a', 1);
	push(stack_a, stack_b, 'b', 1);
	smallest = smallest_value(*stack_a);
	while (smallest--)
		rotate(stack_a, 'a', 1);
	push(stack_a, stack_b, 'b', 1);
	three_nums(stack_a);
	push(stack_b, stack_a, 'a', 1);
	push(stack_b, stack_a, 'a', 1);
	push(stack_b, stack_a, 'a', 1);
}
