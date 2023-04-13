/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-02 - 09:32 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: test vector new
 */

#include "fonction.h"

Test(vector_new, easy) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;

    elem_size = sizeof(char);
    initial_capacity = 16;
    ve = stu_vector_new(elem_size, initial_capacity);
    stu_memcpy(ve->vector, "abcdefghijklmno", ve->ini_size * ve->size);
    cr_assert_str_eq(ve->vector, "abcdefghijklmno");
    free(ve->vector);
    free(ve);
}

Test(vector_new, normal) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;

    elem_size = sizeof(char);
    initial_capacity = 1;
    ve = stu_vector_new(elem_size, initial_capacity);
    stu_memcpy(ve->vector, "", ve->ini_size * ve->size);
    cr_assert_str_eq(ve->vector, "");
    free(ve->vector);
    free(ve);
}

Test(vector_new, hard) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;
    int test[6] = {0, 0, 0, 0, 0, 0};

    elem_size = sizeof(int);
    initial_capacity = 6;
    ve = stu_vector_new(elem_size, initial_capacity);
    stu_memcpy(ve->vector, &test, ve->ini_size * ve->size);
    cr_assert(eq(int[initial_capacity],ve->vector, test));
    free(ve->vector);
    free(ve);
}

Test(vector_new, demon) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;
    int test[6] = {5, 2, 9, 1, 5, 8};

    elem_size = sizeof(int);
    initial_capacity = 6;
    ve = stu_vector_new(elem_size, initial_capacity);
    stu_memcpy(ve->vector, &test, ve->ini_size * ve->size);
    cr_assert(eq(int[ve->ini_size],ve->vector, test));
    free(ve->vector);
    free(ve);
}
