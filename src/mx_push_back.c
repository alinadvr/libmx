#include "libmx.h"

void mx_push_back(t_list **list, void *data)
{
    t_list *node = mx_create_node(data);

    if (node == NULL) return;

    if (*list == NULL)
        *list = node;
    else
    {
        t_list *current_node = *list;

        while (current_node->next != NULL)
            current_node = current_node->next;
        
        current_node->next = node;
    }
}
