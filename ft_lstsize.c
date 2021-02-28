#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*prt;
	int		size;

	if (!lst)
		return (0);
	size = 0;
	ptr = lst;
	while (ptr)
	{
		ptr = ptr->next;
		size++;
	}
	return (size);
}
