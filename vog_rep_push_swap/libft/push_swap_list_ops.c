/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:15:08 by luferna3          #+#    #+#             */
/*   Updated: 2025/05/19 05:12:10 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew_ps(int content)
{
	t_stack	*result;

	result = (t_stack *)malloc(sizeof(*result));
	if (!result)
	{
		return (NULL);
	}
	result->value = content;
	result->next = NULL;
	return (result);
}

void	ft_lstadd_front_ps(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize_ps(t_stack *lst)
{
	int		count;
	t_stack	*temp;

	count = 0;
	temp = lst;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}
