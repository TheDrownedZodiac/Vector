/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-06 - 11:04 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector pop front test
 */

#include "fonction.h"

Test(vector_pop_front, normal) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;

    elem_size = sizeof(char);
    initial_capacity = 1;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 1;
    ve->len_use = ve->len_tab * elem_size;
    stu_memcpy(ve->vector, "j", ve->ini_size * ve->size);
    stu_vector_pop_front(ve);
    cr_assert_eq(ve->vector, stu_vector_get_at(ve, 0));
    stu_vector_delete(ve);
}

Test(vector_pop_front, demon) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;
    int test_1[6] = {1, 2, 3, 4, 5, 6};

    elem_size = sizeof(int);
    initial_capacity = 6;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 6;
    ve->len_use = (ve->len_tab * elem_size);
    stu_memcpy(ve->vector, &test_1, ve->len_use);
    stu_vector_pop_front(ve);
    cr_assert(eq(int[5], ve->vector, stu_vector_get_front(ve)));
    stu_vector_delete(ve);
}
