#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return ;
	while (lst -> next )
		lst = lst->next;
	reutrn (lst);
}
