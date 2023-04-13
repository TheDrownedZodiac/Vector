/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-06 - 11:08 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector erase at test
 */

#include "fonction.h"

Test(vector_erase_at, easy) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int pos;
    unsigned int initial_capacity;
    unsigned int count;

    pos = 6;
    elem_size = sizeof(char);
    initial_capacity = 17;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 17;
    ve->len_use = ve->len_tab * elem_size;
    stu_memcpy(ve->vector, "abcdefgghijklmnop", 17);
    stu_vector_erase_at(ve, pos);
    count = 0;
    while (count < ve->len_tab) {
        cr_assert_eq(*((char *) ve->vector + count), 'a' + count);
        count += 1;
    }
    stu_vector_delete(ve);
}


Test(vector_erase_at, normal) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int pos;
    unsigned int initial_capacity;
    unsigned int count;

    pos = 0;
    elem_size = sizeof(char);
    initial_capacity = 1;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 1;
    ve->len_use = ve->len_tab * elem_size;
    stu_memcpy(ve->vector, "j", ve->ini_size * ve->size);
    stu_vector_erase_at(ve, pos);
    count = 0;
    while (count < ve->len_tab) {
        cr_assert_eq(*((char *) ve->vector + count), 'a' + count);
        count += 1;
    }
    stu_vector_delete(ve);
}

Test(vector_erase_at, demon) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;
    unsigned int pos;
    int test_1[6] = {1, 2, 3, 4, 5, 6};
    int test_2[5] = {2, 3, 4, 5, 6};

    pos = 0;
    elem_size = sizeof(int);
    initial_capacity = 6;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 6;
    ve->len_use = (ve->len_tab * elem_size);
    stu_memcpy(ve->vector, &test_1, ve->len_use);
    stu_vector_erase_at(ve, pos);
    cr_assert(eq(int[5], ve->vector, test_2));
    stu_vector_delete(ve);
}
