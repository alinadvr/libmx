#include "libmx.h"

int mx_list_size(t_list *list)
{
    t_list *current_node = list;
    int size = 0;

    while (current_node->next != NULL)
    {
        size++;
        current_node = current_node->next;
    }

    return size + 1;
}
