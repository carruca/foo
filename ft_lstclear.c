#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	tmp = NULL;
	while (*lst)
	{
		tmp = lst->next;
		del(lst->content);
		free(lst);
		*lst = tmp;
	}
	*lst = NULL;
}
