#include "sort.h"
/**
 * insertion_sort_list - t sorts a doubly linked list of integers in 
 * ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{   
    listint_t *current = (*list)->next;
    listint_t *temp = current;
    listint_t *node1 = temp->prev;
    listint_t *node2 = temp;

    if (!list || !*list || !(*list)->next)
        return;

    while (current)
    {
    
        while (temp->prev && temp->n < temp->prev->n)
        {
            if (node1->prev)
                node1->prev->next = node2;
            else
                *list = node2;

            if (node2->next)
                node2->next->prev = node1;

            node1->next = node2->next;
            node2->prev = node1->prev;
            node2->next = node1;
            node1->prev = node2;

            print_list(*list);
        }
        current = current->next;
    }
}
