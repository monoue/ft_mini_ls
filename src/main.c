/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:33:20 by monoue            #+#    #+#             */
/*   Updated: 2020/12/04 09:09:06 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

bool	g_error_flag = false;

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc > 1)
	{
		ft_putstr_fd(ARG_ERR, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	list_dir();
	if (g_error_flag == true)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
