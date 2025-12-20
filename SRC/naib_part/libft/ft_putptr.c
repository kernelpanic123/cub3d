/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:47:02 by nmagamad          #+#    #+#             */
/*   Updated: 2025/04/26 21:13:45 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(unsigned long long nb)
{
	int		count;

	count = 0;
	if (!nb)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthex(nb, 0);
	return (count);
}
