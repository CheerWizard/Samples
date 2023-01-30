#pragma once

#include "Timer.h"
#include <vector>

void swap(int *xp, int *yp);

int* selection_sort(int arr[], int n);

int* bubble_sort(int arr[], int n);

int* insert_sort(int arr[], int n);
float* insert_sort(float arr[], int n);

int* binary_insert_sort(int arr[], int n);

int* merge_sort(int arr[], int n);

int* quick_sort(int arr[], int n);

int* quick_sort_iter(int arr[], int n);

int* intro_sort(int arr[], int n);

int* heap_sort(int arr[], int n);

template<size_t n>
void bucket_sort(float arr[]) {
    MEASURE_FUNC()
    // build buckets
    std::vector<float> b[n];
    for (int i = 0 ; i < n ; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }
    // insert sort on each bucket
    for (int i = 0 ; i < n ; i++) {
        insert_sort(b[i].data(), (int)b[i].size());
    }
    // merge buckets
    int index = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
        }
    }
}

void tree_sort(int arr[], int n);