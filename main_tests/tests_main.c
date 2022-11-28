#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "../fonctions.h"

//fonction qui libère l'ensemble de la mémoire de la liste


void test_init(void)
{
    linked_list *test_init = new_element(5);
    CU_ASSERT(test_init->next == NULL);
    CU_ASSERT(test_init->previous == NULL);
    CU_ASSERT(test_init->data == 5);
    CU_ASSERT(length(test_init) == 1);
    list_free(test_init);
    
}



void test_push(void)
{
    linked_list *test_push = new_element(5);
    int liste_value[]={5,12,25,60};
    linked_list *pt=test_push;
    CU_ASSERT(length(test_push) == 1);
    push(test_push, 12);
    CU_ASSERT(length(test_push) == 2);
    push(test_push, 25);
    CU_ASSERT(length(test_push) == 3);
    push(test_push, 12);
    for(int i=0;i<3;i++){
        CU_ASSERT(pt->data==liste_value[i]);
        pt=pt->next;
    }
    list_free(test_push);
}

void test_pop(void)
{
    linked_list *test_pop = new_element(5);
    int liste_value[]={12,25,9,45,4};
    for(int i=0;i<5;i++){
        push(test_pop, liste_value[i]);
    }
    CU_ASSERT(length(test_pop) == 6);
    linked_list *pt=test_pop;
    CU_ASSERT(pt->data==5);
    for(int i=0;i<5;i++){
        pt = pt->next;
        CU_ASSERT(pt->data==liste_value[i]);
    }
    pop(test_pop);
    CU_ASSERT(length(test_pop) == 5);
    pt = pt->previous;
    CU_ASSERT(pt->data==45);
    pop(test_pop);
    CU_ASSERT(length(test_pop) == 4);
    pt = pt->previous;
    CU_ASSERT(pt->data==9);
    list_free(test_pop);
}

void test_add_index(void)
{
    linked_list *test_add_index = new_element(10);
    linked_list *pt=test_add_index;
    int list_value[]={20,40,50,60,70};
    int new_list_value[]={20,30,40,50,60,70};
    for(int i=0;i<5;i++){
        push(test_add_index, list_value[i]);
    }
    CU_ASSERT(length(test_add_index) == 6);
    add_index(test_add_index, 30, 3);
    CU_ASSERT(length(test_add_index) == 7);
    pt=pt->next;
    for(int i=0;i<5;i++){
        CU_ASSERT(pt->data==new_list_value[i]);
        pt=pt->next;
    }
    list_free(test_add_index);
}

void test_add_before(void)
{
    linked_list *test_add_before = new_element(10);
    linked_list *pt=test_add_before;
    int liste_value[]={20,30,40,50,60,70};
    int new_list_value[]={20,30,40,45,50,60,70};
    for(int i=0;i<6;i++){
        push(test_add_before, liste_value[i]);
    }
    CU_ASSERT(length(test_add_before) == 7);
    add_before(test_add_before, 45, 50);
    CU_ASSERT(length(test_add_before) == 8);
    for(int i=0;i<7;i++){
        pt=pt->next;
        CU_ASSERT(pt->data==new_list_value[i]);
    };
    list_free(test_add_before);
}

void test_add_after(void)
{
    linked_list *test_add_after = new_element(10);
    linked_list *pt=test_add_after;
    int list_value[]={20,30,40,50,60,70};
    int new_list_value[]={20,30,40,45,50,60,70};
    for(int i=0;i<6;i++){
        push(test_add_after, list_value[i]);
    }
    CU_ASSERT(length(test_add_after) == 7);
    add_after(test_add_after, 45, 40);
    CU_ASSERT(length(test_add_after) == 8);
    for(int i=0;i<7;i++){
        pt=pt->next;
        CU_ASSERT(pt->data==new_list_value[i]);
    };
    list_free(test_add_after);
}

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

int main()
{
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_1", init_suite, clean_suite);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if (
        NULL == CU_add_test(pSuite, "test initialisation", test_init) ||
        NULL == CU_add_test(pSuite, "test de la fonction push", test_push) ||
        NULL == CU_add_test(pSuite, "test de la fonction pop", test_pop) ||
        NULL == CU_add_test(pSuite, "test de la fonction add before", test_add_before) ||
        NULL == CU_add_test(pSuite, "test de la fonction add index", test_add_index) ||
        NULL == CU_add_test(pSuite, "test de la fonction add after", test_add_after))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}