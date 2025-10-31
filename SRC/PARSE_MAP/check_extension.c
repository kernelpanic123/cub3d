/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:08:03 by abtouait          #+#    #+#             */
/*   Updated: 2025/10/31 13:58:31 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int check_extension(char *str)
{
	int i;

	i = ft_strlen(str);
	i--;
	if (str[i] != 'b')
		return (FALSE);
	i--;
	if (str[i] != 'u')
		return (FALSE);
	i--;
	if (str[i] != 'c')
		return (FALSE);
	i--;
	if (str[i] != '.')
		return (FALSE);
	return (TRUE);
}