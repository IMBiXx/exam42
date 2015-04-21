/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlecart <valentin.lecart@student.4>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 18:34:35 by vlecart           #+#    #+#             */
/*   Updated: 2015/04/21 18:36:19 by vlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		content(char *str, char c, int max)
{
	while (*str && max-- != 0)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	inter(char *str, char *str2)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (content(str2, str[index], -1))
			if (index == 0 || !content(str, str[index], index))
				write(1, &str[index], 1);
		index++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
