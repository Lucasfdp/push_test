/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:37:13 by luferna3          #+#    #+#             */
/*   Updated: 2025/05/06 06:37:49 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	swap(a, 'a', 0);
	swap(b, 'b', 0);
	write(1, "ss\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 'a', 0);
	rotate(b, 'b', 0);
	write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 'a', 0);
	reverse_rotate(b, 'b', 0);
	write(1, "rrr\n", 4);
}
