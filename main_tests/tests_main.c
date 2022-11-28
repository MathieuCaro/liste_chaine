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
}

void test_push(void)
{
    linked_list *test_push = new_element(5);
    CU_ASSERT(length(test_push) == 1);
    push(test_push, 12);
    CU_ASSERT(test_push->next->data == 12);
    CU_ASSERT(length(test_push) == 2);
    CU_ASSERT(test_push->next->previous->data == 5);
    push(test_push, 25);
    CU_ASSERT(length(test_push) == 3);
    CU_ASSERT(test_push->next->next->data == 25);
    CU_ASSERT(test_push->next->next->previous->data == 12);
    CU_ASSERT(test_push->next->next->previous->previous->data == 5);
    //faire un pointeur pour vérifier les différents elementts de la liste
}

void test_pop(void)
{
    linked_list *test_pop = new_element(5);
    push(test_pop, 12);
    push(test_pop, 25);
    push(test_pop, 9);
    push(test_pop, 45);
    push(test_pop, 4);
    CU_ASSERT(length(test_pop) == 6);
    CU_ASSERT(test_pop->next->data == 12);
    CU_ASSERT(test_pop->next->next->data == 25);
    CU_ASSERT(test_pop->next->next->next->data == 9);
    CU_ASSERT(test_pop->next->next->next->next->data == 45);
    pop(test_pop);
    CU_ASSERT(length(test_pop) == 5);
    CU_ASSERT(test_pop->next->next->next->next->next == NULL);
    pop(test_pop);
    CU_ASSERT(length(test_pop) == 4);
    CU_ASSERT(test_pop->next->next->next->next == NULL);
}

void test_add_index(void)
{
    linked_list *test_add_index = new_element(10);
    push(test_add_index, 20);
    push(test_add_index, 30);
    push(test_add_index, 40);
    push(test_add_index, 50);
    push(test_add_index, 60);
    push(test_add_index, 70);
    CU_ASSERT(length(test_add_index) == 7);
    // display_list(test_add_index);
    add_index(test_add_index, 30, 2);
    // display_list(test_add_index);
    CU_ASSERT(test_add_index->next->next->next->data == 30);
}

void test_add_before(void)
{
    linked_list *test_add_before = new_element(10);
    push(test_add_before, 20);
    push(test_add_before, 30);
    push(test_add_before, 40);
    push(test_add_before, 50);
    push(test_add_before, 60);
    push(test_add_before, 70);
    // display_list(test_add_before);
    CU_ASSERT(length(test_add_before) == 7);
    add_before(test_add_before, 45, 50);
    // display_list(test_add_before);
    CU_ASSERT(test_add_before->next->next->next->next->data == 45);
}

void test_add_after(void)
{
    linked_list *test_add_after = new_element(10);
    push(test_add_after, 20);
    push(test_add_after, 30);
    push(test_add_after, 40);
    push(test_add_after, 50);
    push(test_add_after, 60);
    push(test_add_after, 70);
    display_list(test_add_after);
    CU_ASSERT(length(test_add_after) == 7);
    add_after(test_add_after, 45, 50);
    display_list(test_add_after);
    CU_ASSERT(test_add_after->next->next->next->next->data == 45);
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