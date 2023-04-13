/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-02 - 14:11 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector push back
 */

#include "fonction.h"

Test(vector_push_back, easy) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;

    elem_size = sizeof(char);
    initial_capacity = 16;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 15;
    ve->len_use = ve->len_tab * elem_size;
    stu_memcpy(ve->vector, "abcdefghijklmno", ve->ini_size * ve->size);
    stu_vector_push_back(ve, "p");
    cr_assert_str_eq(ve->vector, "abcdefghijklmnop");
    stu_vector_delete(ve);
}

Test(vector_push_back, normal) {
    stu_vector_t *ve;
    char elem;
    unsigned int elem_size;
    unsigned int initial_capacity;

    elem_size = sizeof(char);
    initial_capacity = 1;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab = 1;
    ve->len_use = ve->len_tab * elem_size;
    elem = 'p';
    stu_memcpy(ve->vector, "j", ve->ini_size * ve->size);
    stu_vector_push_back(ve, &elem);
    cr_assert_str_eq(ve->vector, "jp");
    stu_vector_delete(ve);
}

Test(vector_push_back, demon) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;
    int num;
    int test_1[6] = {1, 2, 3, 4, 5, 6};
    int test_2[7] = {1, 2, 3, 4, 5, 6, 7};

    num = 7;
    elem_size = sizeof(int);
    initial_capacity = 7;
    ve = stu_vector_new(elem_size, initial_capacity);
    ve->len_tab += 6;
    ve->len_use += (ve->len_tab * elem_size);
    stu_memcpy(ve->vector, test_1, ve->len_use);
    stu_vector_push_back(ve, &num);
    cr_assert(eq(int[7], ve->vector, test_2));
    stu_vector_delete(ve);
}
