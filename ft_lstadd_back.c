#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*alst;

	alst = *lst;
	if (!alst)
		*lst = new;
	else
	{
		while (alst->next)
			alst = alst->next;
		alst->next = new;
	}
}
