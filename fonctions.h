#ifndef ALLOC_H
#define ALLOC_H

typedef struct linked_list{
    int data;
    struct linked_list* next;
    struct linked_list* previous;

} linked_list;

void push( linked_list *head, int data);
void pop(linked_list*head, int data);



#endif
