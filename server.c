/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:07:06 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/30 00:18:09 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_list	*g_message = NULL;

void	ft_yuno(int signal)
{
	(void)signal;
	ft_lstclear(&g_message, NULL);
	g_message = NULL;
	ft_printf("Le serveur a ete interrompu.");
	exit(0);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit = 7;
	t_list					*key;

	(void)context;
	if (sig == SIGUSR2)
		c = c | (1 << bit);
	bit--;
	if (bit < 0)
	{
		ft_lstadd_back(&g_message, ft_lstnew((void *)(size_t)c));
		if (c == '\0')
		{
			key = g_message;
			while (key)
				free((ft_printf("%c", (char)(size_t)key->content),
						key = key->next, NULL));
			ft_lstclear(&g_message, NULL);
			g_message = NULL;
			ft_printf("\nmessage recu par le serveur\n");
		}
		free((c = 0, bit = 7, NULL));
	}
	if (info)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	signal(SIGINT, ft_yuno);
	pid = getpid();
	ft_printf("The PID = %d\n", pid);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
