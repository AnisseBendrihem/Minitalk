/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:00:21 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/29 23:54:32 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"

void	ft_yuno(int signal);
void	handler(int sig, siginfo_t *info, void *context);
void	ack_handler(int sig);
void	send_character(int pid, char c);
void	send_message(int pid, char *str);

#endif