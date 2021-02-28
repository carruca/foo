#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void (*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	head = new;
	while (lst->next)
	{
		lst = lst->next;
		new->next = ft_lstnew(f(lst->content));
		if (!new->next)
		{
			del(new->content);
			free(new);
			return (NULL);
		}
		new = new->next; 
	}
	return (head);
}
