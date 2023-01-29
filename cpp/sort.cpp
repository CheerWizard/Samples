#include <sort.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int* selection_sort(int arr[], int n) {
    MEASURE_FUNC()

    int i, j, min;

    for (i = 0 ; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }

        if (min != i)
            swap(&arr[min], &arr[i]);
    }

    return arr;
}

int* bubble_sort(int arr[], int n) {
    MEASURE_FUNC()

    bool swapped = false;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }

    return arr;
}

void insert_sort(int arr[], int n, int* result) {
    MEASURE_FUNC()
}