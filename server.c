/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:07:06 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 00:48:23 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void handler (int)
// {

// }

int	main(void)
{
	int pid;

	pid = 0;
	pid = getpid();
	printf("The PID = %d\n", pid);
	while (pid)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}