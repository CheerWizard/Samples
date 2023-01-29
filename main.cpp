#include <find.h>
#include <sort.h>
#include <list.h>

void print(int arr[], int n) {
    cout << "arr[" << n << "]= ";
    for (int i = 0 ; i < n ; i++) {
        cout << arr[i];
        if (i != n - 1) {
            cout << " , ";
        }
    }
    cout << endl;
}

int main() {
    // linear search
    int num[10] = { 0, 2, 3, 6, 4, 5, 98, 45, 1, 34 };
    {
        cout << "linear_search" << endl;
        int i = linear_search(num, 10, 98);
        cout << "index=" << i << endl;
    }
    {
        cout << "linear_sentinel_search" << endl;
        int i = linear_sentinel_search(num, 10, 98);
        cout << "index=" << i << endl;
    }
    // binary search
    int sorted[] = { 0, 10, 34, 45, 54, 55, 76, 100, 107, 108 };
    {
        cout << "binary_search" << endl;
        int i = binary_search(sorted, sizeof(sorted) / sizeof(sorted[0]), 108);
        cout << "index=" << i << endl;
    }
    {
        cout << "meta_binary_search" << endl;
        int i = meta_binary_search(sorted, sizeof(sorted) / sizeof(sorted[0]), 34);
        cout << "index=" << i << endl;
    }
    {
        cout << "ternary_search" << endl;
        int i = ternary_search(sorted, sizeof(sorted) / sizeof(sorted[0]), 108);
        cout << "index=" << i << endl;
    }
    {
        cout << "jump_search" << endl;
        int i = jump_search(sorted, sizeof(sorted) / sizeof(sorted[0]), 10);
        cout << "index=" << i << endl;
    }
    {
        cout << "interpolation_search" << endl;
        int i = interpolation_search(sorted, sizeof(sorted) / sizeof(sorted[0]), 45);
        cout << "index=" << i << endl;
    }
    {
        cout << "exp_search" << endl;
        int i = exp_search(sorted, sizeof(sorted) / sizeof(sorted[0]), 55);
        cout << "index=" << i << endl;
    }
    // select sort
    {
        int unsorted[10] = { 3, 10, 7, 9, -11, -5, 5, -100, 99, 1 };
        int n = sizeof(unsorted) / sizeof(unsorted[0]);
        cout << "selection_sort" << endl;
        print(unsorted, n);
        print(selection_sort(unsorted, n), n);
    }
    // bubble sort
    {
        int unsorted[10] = { 3, 10, 7, 9, -11, -5, 5, -100, 99, 1 };
        int n = sizeof(unsorted) / sizeof(unsorted[0]);
        cout << "bubble_sort" << endl;
        print(unsorted, n);
        print(bubble_sort(unsorted, n), n);
    }
    // insert sort
    {
        int unsorted[10] = { 3, 10, 7, 9, -11, -5, 5, -100, 99, 1 };
        int n = sizeof(unsorted) / sizeof(unsorted[0]);
        int result[10];
        memset(result, 0, sizeof(int) * 10);
        cout << "insert_sort" << endl;
        print(unsorted, n);
        insert_sort(unsorted, n, result);
        print(result, n);
    }
    // insert sort for list
    {
        int unsorted[10] = { 3, 10, 7, 9, -11, -5, 5, -100, 99, 1 };
        int n = sizeof(unsorted) / sizeof(unsorted[0]);

        List list;
        list.fill(unsorted, n);

        list.print();
        cout << "insert_sort_for_list" << endl;
        list.insert_sort();
        list.print();
    }
    return 0;
}
