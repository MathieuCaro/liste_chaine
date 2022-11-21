#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "fonctions.h"

linked_list* new_element(int data){
    linked_list* element =(linked_list*)malloc((sizeof(linked_list)));
    if(element==NULL){
        printf("Probleme d'allocation memoire");
        exit(1);
    }
    element->next=NULL;
    element->previous=NULL;
    element->data=data;
    return element;
}

//push : add an element at the end of the list
void push( linked_list *head, int data){
    linked_list *new_one= head;
    while(new_one->next!=NULL){
        new_one=new_one->next;
    }

    new_one->next=new_element(data);
    new_one->next->previous=new_one;

}

// pop : remove the last element of the list
void pop(linked_list*head, int data){
    linked_list *last_one=head;
    while(last_one->next!=NULL){
        last_one=last_one->next;     
    }
    last_one->previous->next=NULL;
    free(last_one);
}

//length : return the length of the linked list
int length(linked_list*head){
    int compteur=1;
    linked_list *last_one=head;
    while(last_one->next!=NULL){
        compteur+=1;
        last_one=last_one->next;
    }
    return compteur;
}