/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:42:46 by tsierra-          #+#    #+#             */
/*   Updated: 2021/03/01 17:45:49 by tsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_H
# define CHUNK_H

#include <stdint.h>

typedef struct	s_chunk
{
	int			count;
	int			capacity;
	uint8_t		*code;
}				t_chunk;

#endif
