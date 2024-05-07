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

char	*ft_strcpy(char *dest, const char *src)
{
	char	*result;

	result = dest;
	if (!dest || !src)
		return (NULL);
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (result);
}
