/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:01:40 by junghwki          #+#    #+#             */
/*   Updated: 2020/10/19 17:29:29 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*result;
	t_list	*result_temp;

	if (!lst)
		return (NULL);
	temp = lst;
	result = NULL;
	while (temp)
	{
		if (!(result_temp = ft_lstnew(f(temp->content))))
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, result_temp);
		temp = temp->next;
	}
	return (result);
}
