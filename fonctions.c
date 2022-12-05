#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "fonctions.h"

linked_list *new_element(int data)
{
    linked_list *element = (linked_list *)malloc((sizeof(linked_list)));
    if (element == NULL)
    {
        printf("Probleme d'allocation memoire");
        exit(1);
    }
    element->next = NULL;
    element->previous = NULL;
    element->data = data;
    return element;
}

void list_free(linked_list *l)
{
    linked_list *tmp;
    linked_list *first = l;
    while (first)
    {
        tmp = first;
        first = first->next;
        free(tmp);
    }
    if (l != NULL)
    {
        l = NULL;
    }
}

// push : add an element at the end of the list
void push(linked_list *head, int data)
{
    linked_list *new_one = head;
    while (new_one->next != NULL)
    {
        new_one = new_one->next;
    }

    new_one->next = new_element(data);
    new_one->next->previous = new_one;
}

// pop : remove the last element of the list
void pop(linked_list *head)
{
    linked_list *last_one = head;
    while (last_one->next != NULL)
    {
        last_one = last_one->next;
    }
    last_one->previous->next = NULL;
    free(last_one);
}

void add_index(linked_list *head, int data, int index)
{
    linked_list *added_index = head, *temp;
    int compteur = 0;
    while (compteur < index - 1)
    {
        added_index = added_index->next;
        compteur++;
    }

    temp = new_element(data);
    temp->next = added_index;
    temp->previous = added_index->previous;
    added_index->previous->next = temp;
    added_index->previous = temp;
}

void display_list(linked_list *head)
{
    linked_list *display = head;
    int taille = length(display);
    int compteur = 1;
    while (compteur < taille + 1)
    {
        printf("| %d : %d ", compteur, display->data);
        display = display->next;
        compteur++;
    }
    printf("\n");
}

void add_before(linked_list *head, int data, int value)
{
    linked_list *add_before = head, *temp;
    while ((add_before->data != value) && (add_before->next))
    {
        add_before = add_before->next;
    }
    temp = new_element(data);
    temp->next = add_before;
    temp->previous = add_before->previous;
    add_before->previous->next = temp;
    add_before->previous = temp;
}

void add_after(linked_list *head, int data, int value)
{
    linked_list *add_after = head, *temp;
    while ((add_after->data != value) && (add_after->next))
    {
        add_after = add_after->next;
    }
    temp = new_element(data);
    temp->previous = add_after;
    temp->next = add_after->next;
    add_after->next->previous = temp;
    add_after->next = temp;
}
// length : return the length of the linked list
int length(linked_list *head)
{
    int compteur = 1;
    linked_list *last_one = head;
    while (last_one->next != NULL)
    {
        compteur += 1;
        last_one = last_one->next;
    }
    return compteur;
}

void swap(linked_list *head)
{
}

void revert(linked_list *head)
{
    linked_list *left = head;
    linked_list *right = head;

    while (right->next != NULL)
    {
        right = right->next;
    }
    while (left != right && left->previous != right)
    {

        int temp = left->data;
        left->data = right->data;
        right->data = temp;

        left = left->next;

        right = right->previous;
    }
}
