/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-03 - 15:02 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector get size test
 */

#include "fonction.h"

Test(vector_get_size, easy) {
    stu_vector_t *ve;
    unsigned int elem_size;
    char *test;
    unsigned int initial_capacity;

    test = "abcdefghij";
    elem_size = sizeof(char);
    initial_capacity = 11;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 10;
    ve->len_use = ve->len_tab * elem_size;
    stu_memcpy(ve->vector, test, ve->len_use);
    stu_vector_push_back(ve, "k");
    cr_assert_eq(stu_vector_get_size(ve), ve->len_tab);
    stu_vector_delete(ve);
}

Test(vector_get_size, normal) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;
    int elem;
    int test[6] = {0, 1, 2, 3, 4, 5};

    elem = 1;
    elem_size = sizeof(int);
    initial_capacity = 6;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 6;
    ve->len_use = ve->len_tab * elem_size;
    stu_memcpy(ve->vector, test, ve->len_use);
    stu_vector_push_back(ve, &elem);
    cr_assert_eq(stu_vector_get_size(ve), ve->len_tab);
    stu_vector_delete(ve);
}


Test(vector_get_size, hard) {
    stu_vector_t *ve;
    unsigned int elem_size;
    char *test;
    unsigned int initial_capacity;

    test = "abcdefghij";
    elem_size = sizeof(char);
    initial_capacity = 11;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 10;
    ve->len_use = ve->len_tab * elem_size;
    stu_memcpy(ve->vector, test, ve->len_use);
    stu_vector_pop_back(ve);
    cr_assert_eq(stu_vector_get_size(ve), ve->len_tab);
    stu_vector_delete(ve);
}

Test(vector_get_size, demon) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;
    int test[6] = {0, 1, 2, 3, 4, 5};

    elem_size = sizeof(int);
    initial_capacity = 6;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 6;
    ve->len_use = ve->len_tab * elem_size;
    stu_memcpy(ve->vector, test, ve->len_use);
    stu_vector_pop_back(ve);
    cr_assert_eq(stu_vector_get_size(ve), ve->len_tab);
    stu_vector_delete(ve);
}

