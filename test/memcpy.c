/*
 * E89 Pedagogical & Technical Lab
 * project:     day2
 * created on:  2023-01-31 - 11:05 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: test memcpy
 */

#include <criterion/criterion.h>
#include "fonction.h"


Test(memcpy, easy) {

    unsigned int arr_size;
    char *array;
    char *test;

    test = "฿ 4'048'900'000";
    arr_size = sizeof(char) * 13;
    array = malloc(arr_size);
    stu_memcpy(array, test, arr_size);
    cr_assert_str_eq(array, "฿ 4'048'900");
    free(array);
}


Test(memcpy, normal) {

    int i;
    unsigned int arr_size;
    int *array;
    int test[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    i = 2;
    arr_size = sizeof(int) * 5;
    array = malloc(arr_size);
    stu_memcpy(array, &test, arr_size);
    cr_assert_eq(array[i], test[i]);
    free(array);
}

Test(memcpy, hard) {

    unsigned int i;
    unsigned int arr_size;
    int *array;
    int test[12] = {2, 9, 3, 4, 7, 2, 9, 9, 1, 8, 3, 5};

    i = 0;
    arr_size = sizeof(int) * 12;
    array = malloc(arr_size);
    stu_memcpy(array, &test, arr_size);
    while (i < arr_size / 4) {
        cr_expect_eq(array[i], test[i]);
        i += 1;
    }
    free(array);
}
