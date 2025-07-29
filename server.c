/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:07:06 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/29 06:53:30 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit = 7;
	static t_list			*message;
	t_list					*key;

	(void)context;
	if (sig == SIGUSR2)
		c = c | (1 << bit);
	bit--;
	if (bit < 0)
	{
		ft_lstadd_back(&message, ft_lstnew((void *)(size_t)c));
		if (c == '\0')
		{
			key = message;
			while (key)
			{
				ft_printf("%c", (char)(size_t)key->content);
				key = key->next;
			}
			ft_lstclear(&message, NULL);
			message = NULL;
			ft_printf("\nMessage reçu et serveur terminé proprement\n");
		}
		c = 0;
		bit = 7;
	}
	// 👉 Envoi accusé de réception
	if (info)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_printf("The PID = %d\n", pid);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO; // 👈 Permet d'accéder à info->si_pid
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
