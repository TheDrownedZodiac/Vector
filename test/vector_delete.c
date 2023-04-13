/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-02 - 09:32 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: test vector new
 */

#include "fonction.h"

Test(vector_delete, easy, .signal = SIGSEGV) {
    stu_vector_t *ve;
    unsigned int elem_size;
    unsigned int initial_capacity;

    elem_size = sizeof(char);
    initial_capacity = 16;
    ve = stu_vector_new(elem_size, initial_capacity);
    stu_vector_delete(ve);
    stu_memset(ve->vector, 0, 16);
}
