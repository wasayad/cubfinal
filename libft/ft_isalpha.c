/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isalpha.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 17:35:58 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 15:05:57 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
	{
		return (1);
	}
	else
		return (0);
}
