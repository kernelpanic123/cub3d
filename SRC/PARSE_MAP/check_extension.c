/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:08:03 by abtouait          #+#    #+#             */
/*   Updated: 2025/10/31 15:52:39 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int open_map(char *str)
{
	int fd;
	
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	return (TRUE);
}

int check_extension(char *str)
{
	int i;

	if (str == NULL)
		return (FALSE);
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
int smol_parse(int argc, char **argv)
{
	if (argc != 2)
		return (FALSE);
	if (check_extension(argv[1]) == FALSE)
		return (FALSE);
	if (open_map(argv[1]) == FALSE)
		return (FALSE);
	return (TRUE);
}