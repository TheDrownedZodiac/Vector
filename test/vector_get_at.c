/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-03 - 10:20 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector get at
 */

#include "fonction.h"

Test(vector_get_at, easy) {
    stu_vector_t *ve;
    unsigned int elem_size;
    int elem;
    unsigned int initial_capacity;

    elem = 1;
    elem_size = sizeof(char);
    initial_capacity = 16;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 15;
    ve->len_use = ve->len_tab * elem_size;
    stu_memcpy(ve->vector, "abcdefghijklmno", ve->ini_size * ve->size);
    cr_assert_eq(stu_vector_get_at(ve, elem), (ve->vector + elem * ve->size));
    stu_vector_delete(ve);
}

Test(vector_get_at, normal) {
    stu_vector_t *ve;
    unsigned int elem_size;
    int elem;
    unsigned int initial_capacity;

    elem = 0;
    elem_size = sizeof(char);
    initial_capacity = 1;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 1;
    ve->len_use = ve->len_tab * elem_size;
    stu_memcpy(ve->vector, "j", ve->ini_size * ve->size);
    cr_assert_eq(stu_vector_get_at(ve, elem), (ve->vector + elem * ve->size));
    stu_vector_delete(ve);
}

Test(vector_get_at, demon) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;
    int elem;
    int test_1[6] = {1, 2, 3, 4, 5, 6};

    elem = 6;
    elem_size = sizeof(int);
    initial_capacity = 6;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab += 6;
    ve->len_use += (ve->len_tab * elem_size);
    stu_memcpy(ve->vector, &test_1, ve->len_use);
    stu_vector_get_at(ve, 5);
    cr_assert_eq(stu_vector_get_at(ve, elem), (ve->vector + elem * ve->size));
    stu_vector_delete(ve);
}
