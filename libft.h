/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:54:39 by tsierra-          #+#    #+#             */
/*   Updated: 2021/03/01 18:42:13 by tsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include "chunk.h"

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char	**ft_split(char const *s, char c);
void	free_2d(char **ptr);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **list, t_list *new);

#endif
