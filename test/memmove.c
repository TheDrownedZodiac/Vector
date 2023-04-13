/*
 * E89 Pedagogical & Technical Lab
 * project:     day2
 * created on:  2023-02-01 - 11:25 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: memmove
 */

#include <criterion/criterion.h>
#include "fonction.h"

Test(memmove, rightward) {
    int *arr;
    int i;
    int cmp;

    arr = malloc(sizeof(int) * 4);
    arr[0] = 4;
    arr[1] = 5;
    arr[2] = 6;
    stu_memmove(&arr[1], arr, sizeof(int) * 3);
    arr[0] = 3;
    i = 0;
    cmp = 3;
    while (i < 4) {
        cr_expect_eq(arr[i], cmp);
        i += 1;
        cmp += 1;
    }
}

Test(memmove, leftward) {
    int *arr;
    int i;
    int cmp;

    arr = malloc(sizeof(int) * 4);
    arr[0] = 3;
    arr[1] = 4;
    arr[2] = 5;
    arr[3] = 6;
    stu_memmove(arr, &arr[1], sizeof(int) * 3);
    i = 0;
    cmp = 4;
    while (i < 3) {
        cr_expect_eq(arr[i], cmp);
        i += 1;
        cmp += 1;
    }
}
