/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-03 - 16:01 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector insert at test
 */

#include "fonction.h"

Test(vector_insert_at, easy) {
    stu_vector_t *ve;
    unsigned int elem_size;
    char *elem;
    unsigned int initial_capacity;

    elem = "M";
    elem_size = sizeof(char);
    initial_capacity = 16;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 15;
    ve->len_use = ve->len_tab * elem_size;
    stu_memcpy(ve->vector, "abcdefghijklmno", ve->ini_size * ve->size);
    cr_assert_str_eq(stu_vector_insert_at(ve, 6, elem), "abcdefMghijklmno");
    stu_vector_delete(ve);
}

Test(vector_insert_at, normal) {
    stu_vector_t *ve;
    unsigned int elem_size;
    char *elem;
    unsigned int initial_capacity;

    elem = "A";
    elem_size = sizeof(char);
    initial_capacity = 1;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 1;
    ve->len_use = ve->len_tab * elem_size;
    stu_memcpy(ve->vector, "j", ve->ini_size * ve->size);
    cr_assert_str_eq(stu_vector_insert_at(ve, 0, elem), "Aj");
    stu_vector_delete(ve);
}

Test(vector_insert_at, demon) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;
    int elem;
    int test_1[6] = {1, 2, 3, 4, 5, 6};
    int test_2[7] = {0, 1, 2, 3, 4, 5, 6};

    elem = 0;
    elem_size = sizeof(int);
    initial_capacity = 6;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 6;
    ve->len_use = (ve->len_tab * elem_size);
    stu_memcpy(ve->vector, &test_1, ve->len_use);
    cr_assert(eq(int[7], stu_vector_insert_at(ve, 0, &elem), test_2));
    stu_vector_delete(ve);
}
