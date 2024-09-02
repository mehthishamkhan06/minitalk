/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:52:53 by mohkhan           #+#    #+#             */
/*   Updated: 2024/06/24 14:52:57 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_hexaddr(unsigned long n);
int		ft_rnputnbr(int n);
int		ft_unsignint(unsigned int n);
int		ft_hexsm(unsigned int n);
int		ft_hexcap(unsigned int n);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif