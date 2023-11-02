#include "libmx.h"

void mx_pop_back(t_list **head)
{
    if (*head == NULL) return;

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        t_list *current_node = *head;

        while (current_node->next != NULL)
        {
            
            if (current_node->next->next == NULL)
            {
                free(current_node->next);
                current_node->next = NULL;
            }
            else
                current_node = current_node->next;
       
        }
        
    }
}
