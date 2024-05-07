/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:32:15 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/07 11:04:21 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;

	if (!dst && !src)
		return (0);
	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	while (n--)
		*uc_dst++ = *uc_src++;
	return (dst);
}
