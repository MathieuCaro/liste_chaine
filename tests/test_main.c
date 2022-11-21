#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "../fonctions.h"

void test_init(void)
{
    linked_list *test_init = new_element(5);
    CU_ASSERT(test_init->next==NULL);
    CU_ASSERT(test_init->previous==NULL);
    CU_ASSERT(test_init->data==5);
    CU_ASSERT(length(test_init)==1);
}

void test_push(void){
    linked_list *test_push = new_element(5);
    CU_ASSERT(length(test_push)==1);
    push(test_push, 12);
    CU_ASSERT(test_push->next->data==12);
    CU_ASSERT(length(test_push)==2);
    CU_ASSERT(test_push->next->previous->data==5);
    push(test_push, 25);
    CU_ASSERT(length(test_push)==3);
    CU_ASSERT(test_push->next->next->data==25);
    CU_ASSERT(test_push->next->next->previous->data==12);
    CU_ASSERT(test_push->next->next->previous->previous->data==5);
}

void test_pop(void){
    linked_list *test_pop = new_element(5);
    push(test_pop, 12);
    push(test_pop, 25);
    push(test_pop, 9);
    CU_ASSERT(length(test_pop)==2);
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
        NULL == CU_add_test(pSuite, "test initialisation", test_init)||
        NULL == CU_add_test(pSuite, "test de la fonction push", test_push)
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}