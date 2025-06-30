/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:51:14 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/29 23:51:14 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "../libft.h"

/*
Creates a new list with modifications.
Iterates the list ’lst’ and 
	applies the function ’f’ on the content of each node. 
Creates a new list resulting of the successive applications of the function ’f’. 
The ’del’ function is used to delete the content of a node if needed.
lst: The address of a pointer to a node.
f: The address of the function used to iterate on the list.
del: The address of the function used to delete the content of a node if needed.
Returns:
	The new list.
	NULL if the allocation fails.
Since we create and return a new list, new_list itself holds the address (*) 
	of the head node of the newly created list (rather than (**): 
	enough to keep track of the head.
It doesn’t need a double pointer because we're not modifying the list outside 
	of the function; we're just building and returning a new list.
A double pointer (t_list **new_list) would be needed if we wanted ft_lstmap \
	to modify the actual pointer variable that was passed in by reference.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			del(new_content);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
