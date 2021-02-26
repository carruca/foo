/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:11:12 by tsierra-          #+#    #+#             */
/*   Updated: 2021/02/26 15:26:33 by tsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main()
{
	t_list	*list;
	char	str[] = "hello world";

	list = ft_lstnew(str);
	printf("%s\n", list->content);
	return (0);
}
