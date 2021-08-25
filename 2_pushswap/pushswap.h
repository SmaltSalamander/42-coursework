/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:09:40 by sbienias          #+#    #+#             */
/*   Updated: 2021/07/23 15:09:40 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

char	ft_sort(t_list **arr, int arrlen);
int		ft_check_order(t_list *arr, int arrlen);
void	ft_rotating_rb(t_list **wrkngstck);
void	ft_rotating_ra(t_list **arr);
void	ft_rev_rotating_rb(t_list **wrkngstck);
void	ft_rev_rotating_ra(t_list **arr);
void	ft_pushing_pb(t_list **arr, t_list **wrkngstck, int *arrlen);
void	ft_pushing_pa(t_list **arr, t_list **wrkngstck, int *arrlen);

#endif