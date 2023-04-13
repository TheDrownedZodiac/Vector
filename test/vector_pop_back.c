/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-03 - 09:13 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector pop back test
 */

#include "fonction.h"

Test(vector_pop_back, easy) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;

    elem_size = sizeof(char);
    initial_capacity = 16;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 15;
    ve->len_use = ve->len_tab * elem_size;
    stu_memcpy(ve->vector, "abcdefghijklmno", ve->len_use);
    stu_vector_pop_back(ve);
    stu_vector_push_back(ve, "");
    cr_assert_str_eq(ve->vector, "abcdefghijklmn");
    stu_vector_delete(ve);
}

Test(vector_pop_back, normal) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;

    elem_size = sizeof(char);
    initial_capacity = 1;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 1;
    ve->len_use = ve->len_tab * elem_size;
    stu_memcpy(ve->vector, "j", ve->len_use);
    stu_vector_pop_back(ve);
    stu_vector_push_back(ve, "");
    cr_assert_str_eq(ve->vector, "");
    stu_vector_delete(ve);
}

Test(vector_pop_back, demon) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;
    int num = 7;
    int test_1[6] = {1, 2, 3, 4, 5, 6};
    int test_2[6] = {1, 2, 3, 4, 5, 7};

    elem_size = sizeof(int);
    initial_capacity = 7;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab += 6;
    ve->len_use += (ve->len_tab * elem_size);
    stu_memcpy(ve->vector, &test_1, ve->len_use);
    stu_vector_pop_back(ve);
    stu_vector_push_back(ve, &num);
    cr_assert(eq(int[6], ve->vector, test_2));
    stu_vector_delete(ve);
}

