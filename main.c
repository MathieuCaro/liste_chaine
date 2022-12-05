#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "fonctions.h"

int main()
{
    linked_list *head = new_element(1);
    display_list(head);
    add_index(head, 2, 0);
    display_list(head);
    revert(head);
    display_list(head);
    list_free(head);

    return 0;
}
