#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *))
{
    if (lst == NULL || cmp == NULL) return NULL;

    int size = mx_list_size(lst);
    t_list *current_node = lst;

    for (int i = 0; i < size - 1; i++)
    {
        current_node = lst;

        while (current_node != NULL && current_node->next != NULL)
        {
            if (cmp(current_node->data, current_node->next->data))
            {
                void *tmp = current_node->data;
                current_node->data = current_node->next->data;
                current_node->next->data = tmp;
            }

            current_node = current_node->next;
        }
    }

    return lst;
}
