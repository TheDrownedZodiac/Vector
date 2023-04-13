/*
 * E89 Pedagogical & Technical Lab
 * project:     day2
 * created on:  2023-02-01 - 09:41 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: arrset test
 */

#include <criterion/criterion.h>
#include "fonction.h"

Test(arrset, easy) {
    unsigned int elem_size;
    int *array;
    unsigned int i;
    int default_value;

    i = 0;
    default_value = 1970;
    elem_size = sizeof(int);
    array = malloc(elem_size * 89);
    arrset(array, &default_value, elem_size, 89);
    while (i < 89) {
        cr_expect_eq(array[i], default_value);
        i += 1;
    }
    free(array);
}

Test(arrset, normal) {
    unsigned int elem_size;
    char *array;
    unsigned int i;
    char default_value;

    i = 0;
    default_value = 'B';
    elem_size = sizeof(char);
    array = malloc(elem_size * 20);
    arrset(array, &default_value, elem_size, 20);
    while (i < 20) {
        cr_expect_eq(array[i], default_value);
        i += 1;
    }
    free(array);
}
