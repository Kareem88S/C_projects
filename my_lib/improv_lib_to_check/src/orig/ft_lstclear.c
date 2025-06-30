/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:31:41 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/29 22:31:41 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "../libft.h"

/*
Deletes and frees the given node and every successor of that node, 
 using the function ’del’ and free(3). 
 Finally, the pointer to the list must be set to NULL.
lst: The address of a pointer to a node.
del: The address of the function used to delete the content of the node.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp_node_address;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		temp_node_address = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp_node_address;
	}
	*lst = NULL;
}
