/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:15:42 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/07 01:35:16 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*result;
	
	if (!dest || !src)
		return (0);
	result = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (result);
}
