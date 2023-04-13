/*
 * E89 Pedagogical & Technical Lab
 * project:     day2
 * created on:  2023-01-31 - 11:05 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: test memset
 */

#include <criterion/criterion.h>
#include "fonction.h"


Test(memset, easy) {

    unsigned int arr_size;
    char *array;
    char *test;

    test = "KKKKKKKKKKK";
    arr_size = sizeof(char) * 12;
    array = malloc(arr_size);
    stu_memset(array, 'K', arr_size - 1);
    cr_assert_str_eq(array, test);
    free(array);
}


Test(memset, normal) {

    unsigned int arr_size;
    unsigned int i;
    int *array;
    int test[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    i = 0;
    arr_size = sizeof(int) * 12;
    array = malloc(arr_size);
    stu_memset(array, 0, arr_size);
    while (i < arr_size / 4) {
        cr_assert_eq(array[i], test[i]);
        i += 1;
    }
    free(array);
}

Test(memset, hard) {
    unsigned int i;
    unsigned int arr_size;
    int test[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int *array;

    i = 0;
    arr_size = sizeof(int) * 12;
    array = malloc(arr_size);
    stu_memset(array, 2, arr_size);
    stu_memset(array, 0, arr_size);
    while (i < arr_size / 4) {
        cr_assert_eq(array[i], test[i]);
        i += 1;
    }
    free(array);
}
