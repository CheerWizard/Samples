#include <sort.h>
#include <find.h>

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

int* insert_sort(int arr[], int n) {
    MEASURE_FUNC()

    int i, j;
    int key;
    for (i = 1 ; i < n ; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    return arr;
}

float* insert_sort(float arr[], int n) {
    MEASURE_FUNC()

    int i, j;
    float key;
    for (i = 1 ; i < n ; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    return arr;
}

int* binary_insert_sort(int arr[], int n) {
    MEASURE_FUNC()

    int i, j, key, loc;
    for (i = 1 ; i < n ; i++) {
        key = arr[i];
        j = i - 1;
        loc = binary_search_recursive(arr, j + 1, key);
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    return arr;
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* arr1 = static_cast<int*>(alloca(n1 * sizeof(int)));
    int* arr2 = static_cast<int*>(alloca(n2 * sizeof(int)));
    memset(arr1, 0, n1 * sizeof(int));
    memset(arr2, 0, n2 * sizeof(int));

    for (int i = 0 ; i < n1 ; i++) {
        arr1[i] = arr[l + i];
    }

    for (int i = 0 ; i < n2 ; i++) {
        arr2[i] = arr[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int* merge_sort(int arr[], int n) {
    MEASURE_FUNC()
    merge_sort(arr, 0, n - 1);
    return arr;
}

int partition(int arr[], int l, int h) {
    int p = arr[h]; // pick pivot
    int i = l - 1;

    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= p) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);

    return i + 1;
}

void qsort(int arr[], int l, int h) {
    if (l < h) {
        int p = partition(arr, l, h);
        qsort(arr, l, p - 1);
        qsort(arr, p + 1, h);
    }
}

int* quick_sort(int arr[], int n) {
    MEASURE_FUNC()
    qsort(arr, 0, n - 1);
    return arr;
}

int* quick_sort_iter(int arr[], int n) {
    MEASURE_FUNC()
    int l = 0;
    int h = n - 1;
    int* stack = new int[h - l + 1];
    int top = -1;

    stack[++top] = l;
    stack[++top] = h;

    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];

        int p = partition(arr, l, h);

        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }

    delete[] stack;

    return arr;
}

int* median(int* a, int* b, int* c) {
    if (*a < *b && *b < *c)
        return (b);

    if (*a < *c && *c <= *b)
        return (c);

    if (*b <= *a && *a < *c)
        return (a);

    if (*b < *c && *c <= *a)
        return (c);

    if (*c <= *a && *a < *b)
        return (a);

    if (*c <= *b && *b <= *a)
        return (b);

    return 0;
}

void intro_sort(int arr[], int* begin, int* end, int depth) {
    int size = end - begin;

    if (size < 16) {
        binary_insert_sort(arr, size);
        return;
    }

    if (depth == 0) {
//        make_heap(begin, end + 1);
//        heap_sort(begin, end + 1);
        return;
    }

    int* pivot = median(begin, begin + size / 2, end);
}

int* intro_sort(int arr[], int n) {
    int begin = 0;
    int end = n - 1;
    int depth = 2 * log(end - begin);

    return arr;
}

void heapify(int arr[], int n, int i) {
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[max]) {
        max = l;
    }
    if (r < n && arr[r] > arr[max]) {
        max = r;
    }

    if (max != i) {
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}

int* heap_sort(int arr[], int n) {
    MEASURE_FUNC()
    // build max heap
    for (int i = n / 2 - 1 ; i >= 0 ; i--) {
        heapify(arr, n, i);
    }
    // remove root element until size > 1
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    return arr;
}

struct TreeNode {
    int key;
    TreeNode *left, *right;
};

TreeNode* newNode(int item) {
    auto* temp = new TreeNode();
    temp->key = item;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

void storeSorted(TreeNode* root, int arr[], int& i) {
    if (root) {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}

TreeNode* insert(TreeNode* node, int key) {
    if (!node)
        return newNode(key);

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    return node;
}

void tree_sort(int arr[], int n) {
    MEASURE_FUNC()

    TreeNode* root = nullptr;
    // create tree
    for (int i = 0 ; i < n ; i++) {
        root = insert(root, arr[i]);
    }

    int i = 0;
    storeSorted(root, arr, i);
}