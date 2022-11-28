#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "fonctions.h"

int main()
{
    linked_list *head = new_element(1);
    display_list(head);
    push(head, 4);
    display_list(head);
    Clear(head);

    return 0;
}
