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

void	ft_sort(t_list **arr, int arrlen);
int		ft_check_order(t_list *arr, int arrlen);
void	ft_rotating_rb(t_list **wrkngstck, int print);
void	ft_rotating_ra(t_list **arr, int print);
void	ft_rev_rotating_rb(t_list **wrkngstck, int print);
void	ft_rev_rotating_ra(t_list **arr, int print);
void	ft_pushing_pb(t_list **arr, t_list **wrkngstck, int *arrlen, int print);
void	ft_pushing_pa(t_list **arr, t_list **wrkngstck, int *arrlen, int print);
void	ft_swapping(t_list *arr, t_list *wrkngstck, int print);
void	sort_3(t_list **arr, t_list **arr1, int *arrlen);
void	sort_smallstack(t_list **arr, t_list **arr1, int *arrlen);
int		lookforval(t_list *arr, int mode);
void	ft_srtarr(int **array, int size);
int		*calc_median(t_list *arr, int amount, int length);
void	ft_swapping(t_list *arr, t_list *wrkngstck, int print);
int		valatindex(t_list *arr, int index);
int		*canidadates_in_range(t_list **arr, int *ls);

int		dup_check(t_list *array);
int		ft_add_to_array(char *string, t_list **array);
int		error_check_atoi(char *string, int *arrelement);

#endif