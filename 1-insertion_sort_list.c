#include "sort.h"
 
/*function to insert a new listint_t in sorted way in
 a sorted doubly linked list
*/

void sortedInsert(listint_t** head_ref, listint_t* newlistint_t)
{
    listint_t* current;
 
    // if list is empty
    if (*head_ref == NULL)
        *head_ref = newlistint_t;
 
    // if the listint_t is to be inserted at the beginning
    // of the doubly linked list
    else if ((*head_ref)->n >= newlistint_t->n) {
        newlistint_t->next = *head_ref;
        newlistint_t->next->prev = newlistint_t;
        *head_ref = newlistint_t;
    }
 
    else {
        current = *head_ref;
 
        // locate the listint_t after which the new listint_t
        // is to be inserted
        while (current->next != NULL &&
               current->next->n < newlistint_t->n)
            current = current->next;
 
        /*Make the appropriate links */
 
        newlistint_t->next = current->next;
 
        // if the new listint_t is not inserted
        // at the end of the list
        if (current->next != NULL)
            newlistint_t->next->prev = newlistint_t;
 
        current->next = newlistint_t;
        newlistint_t->prev = current;
    }
}
 
// function to sort a doubly linked list using insertion sort
void insertionSort(listint_t** head_ref)
{
    listint_t* sorted = NULL;
 
    listint_t* current = *head_ref;
    while (current != NULL) {
        listint_t* next = current->next;
        current->prev = current->next = NULL;
        sortedInsert(&sorted, current);
        current = next;
    }
 
    /*Update head_ref to point to sorted doubly linked list
    *head_ref = sorted;
    */
}
