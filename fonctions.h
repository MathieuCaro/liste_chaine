#ifndef ALLOC_H
#define ALLOC_H

typedef struct linked_list
{
    int data;
    struct linked_list *next;
    struct linked_list *previous;

} linked_list;

linked_list *new_element(int data);

void push(linked_list *head, int data);
void pop(linked_list *head);
int length(linked_list *head);
void add_index(linked_list *head, int data, int index);
void display_list(linked_list *head);
void add_before(linked_list *head, int data, int value);
void add_after(linked_list *head, int data, int value);
void list_free(linked_list *l);
void revert(linked_list *head);

#endif