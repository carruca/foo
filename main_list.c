/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:11:12 by tsierra-          #+#    #+#             */
/*   Updated: 2021/03/01 18:54:52 by tsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	chunk_init(t_chunk *chunk)
{
	chunk->count = 0;
	chunk->capacity = 0;
	chunk->code = NULL;
}

int		main(int argc, char **argv, char **environ)
{
//	t_list	*lst;
//	char	*str = "hello world";
	char	*ptr = "the back add";
	char	**tokens;
	t_chunk	chunk;

	chunk_init(&chunk);
	printf("%d\n%d\n%s\n", chunk.capacity, chunk.count, chunk.code);
//	lst = ft_lstnew(str);
//	printf("%s\n", lst->content);
//	ft_lstadd_back(&lst, ft_lstnew(ptr));
/*	while (lst->next)
	{
		lst = lst->next;
		printf("%s\n", lst->content);
	}*/
	tokens = ft_split(ptr, ' ');
	while (*tokens)
	{
		printf("%s\n", *tokens);
		tokens++;
	}
	free_2d(tokens);
//	while (*environ)
//	{
//		printf("%s\n", *environ);
//		environ++;
//	}
	return (0);
}
