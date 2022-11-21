#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "fonctions.h"

linked_list* new_element(int data){
    linked_list* element =(linked_list*)malloc((sizeof(linked_list)));
    element->next=NULL;
    element->previous=NULL;
    element->data=data;
    return element;
}

//push : add an element at the end of the list
void push( linked_list *head, int data){
    linked_list *new_one= head;
    while(new_one->next=NULL){
        new_one=new_one->next;
    }

    new_one->next=new_element(data);
    new_one->next->previous=new_one;

}

// pop : remove the last element of the list
void pop(linked_list*head, int data){
    linked_list *last_one=head;
    while(last_one->next!=NULL){
        last_one=last_one->previous;
        last_one->next=NULL;
        free(last_one->next);
    }
}
