#include "libmx.h"

void mx_pop_front(t_list **head)
{
    if (*head == NULL) return;

    t_list *tmp = (*head)->next;
    free(*head);
    *head = tmp; 
}
