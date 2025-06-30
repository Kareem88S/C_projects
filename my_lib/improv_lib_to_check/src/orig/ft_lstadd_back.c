/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:35:29 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/29 21:35:29 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Adds the node ’new’ at the end of the list.
lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be added to the list.
On empty list, new becomes new-head
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*traverser;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	traverser = *lst;
	while (traverser->next != NULL)
		traverser = traverser->next;
	traverser->next = new;
}
