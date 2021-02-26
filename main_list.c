/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:11:12 by tsierra-          #+#    #+#             */
/*   Updated: 2021/02/26 17:13:06 by tsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
extern char **environ;

int	main()
{
	t_list	*list;
	char	str[] = "hello world";
	char	**nv = environ;

	list = ft_lstnew(str);
	printf("%s\n", list->content);
	while (*nv)
	{
		printf("%s\n", *nv);
		nv++;
	}
	return (0);
}
