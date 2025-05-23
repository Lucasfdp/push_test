/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:14:33 by luferna3          #+#    #+#             */
/*   Updated: 2025/05/06 06:37:01 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char name, int print_op)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (print_op)
	{
		if (name == 'a')
			write(1, "sa\n", 3);
		else if (name == 'b')
			write(1, "sb\n", 3);
	}
}

void	push(t_stack **src, t_stack **dest, char name, int print_op)
{
	t_stack	*temp;

	if (!(*src))
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	if (print_op)
	{
		if (name == 'a')
			write(1, "pa\n", 3);
		else if (name == 'b')
			write(1, "pb\n", 3);
	}
}

void	rotate(t_stack **stack, char name, int print_op)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	if (print_op)
	{
		if (name == 'a')
			write(1, "ra\n", 3);
		else if (name == 'b')
			write(1, "rb\n", 3);
	}
}

void	reverse_rotate(t_stack **stack, char name, int print_op)
{
	t_stack	*scnd_last;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	scnd_last = NULL;
	last = *stack;
	while (last->next)
	{
		scnd_last = last;
		last = last->next;
	}
	if (scnd_last)
		scnd_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (print_op)
	{
		if (name == 'a')
			write(1, "rra\n", 4);
		else if (name == 'b')
			write(1, "rrb\n", 4);
	}
}
