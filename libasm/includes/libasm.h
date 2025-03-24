/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:25:36 by qbanet            #+#    #+#             */
/*   Updated: 2025/03/21 15:29:09 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef _LIBASM_H
	#define _LIBASM_H

	# include <stdlib.h>

	// Mendatory
	size_t	ft_strlen(char *str);
	int		ft_strcmp(const char *s1, const char *s2);
	char	*ft_strcpy(char *dst, const char *src);
	char	*ft_strdup(const char *s);

	ssize_t	ft_read(int fd, void *buf, size_t count);
	ssize_t	ft_write(int fd, const void *buf, size_t count);

	// Bonus (si activé)
	typedef struct s_list {
		void			*data;
		struct s_list	*next;
	}	t_list;

	int		ft_list_size(t_list *begin_list);
	int		ft_atoi_base(char *str, char *base);
	void	ft_list_sort(t_list **begin_list, int (*cmp)());
	void	*ft_list_push_front(t_list **begin_list, void *data);
	void	ft_list_remove_if(t_list **begin_list,
								void *data_ref,
								int(*cmp)(),
								void (*free_fct)(void *));



#endif