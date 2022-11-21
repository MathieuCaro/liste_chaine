#ifndef ALLOC_H
#define ALLOC_H

typedef struct linked_list{
    int data;
    struct linked_list* next;
    struct linked_list* previous;

} linked_list;

linked_list* new_element(int data);
void push( linked_list *head, int data);
void pop(linked_list*head, int data);
int length(linked_list*head);



#endif
