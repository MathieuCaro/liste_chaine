#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "fonctions.h"

int main()
{
    linked_list *head = new_element(1);
    push(head,4);
    printf("Longueur de la liste chainee : %d\n", length(head));
    return 0;
}
