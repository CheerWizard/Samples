#include <find.h>

int linear_sentinel_search(int arr[], int n, int x) {
    MEASURE_FUNC()

    int last = arr[n - 1];
    arr[n - 1] = x;

    int i = 0;
    while (arr[i] != x)
        i++;

    arr[n - 1] = last;

    if (i < n - 1) {
        return i;
    }

    if (arr[n - 1] == x) {
        return n - 1;
    }

    return -1;
}

int linear_search(int arr[], int n, int x) {
    MEASURE_FUNC()

    for (int i = 0 ; i < n ; i++) {
        if (x == arr[i]) {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int l, int r, int x) {
    MEASURE_FUNC()

    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return -1;
}

int binary_search(int arr[], int n, int x) {
    return binary_search(arr, 0, n - 1, x);
}

int meta_binary_search(int arr[], int n, int x) {
    MEASURE_FUNC()

    int lg = log2((float) n - 1) + 1;
    int p = 0;
    for (int i = lg ; i >= 0; i--) {
        if (arr[p] == x)
            return p;

        int new_p = p | (1 << i);

        if ((new_p < n) && (arr[new_p] <= x))
            p = new_p;
    }

    return arr[p] == x ? p : -1;
}

int ternary_search(int arr[], int n, int x) {
    MEASURE_FUNC()

    int l = 0;
    int r = n - 1;
    while (r >= l) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;

        if (arr[m1] == x)
            return m1;
        if (arr[m2] == x)
            return m2;

        if (arr[m1] > x) {
            r = m2 - 1;
        } else if (arr[m2] < x) {
            l = m1 + 1;
        } else {
            l = m1 + 1;
            r = m2 - 1;
        }
    }

    return -1;
}

int jump_search(int arr[], int n, int x) {
    MEASURE_FUNC()

    int step = sqrt((float)n);

    int prev = 0;
    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt((float)n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x) {
        prev++;

        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == x)
        return prev;

    return -1;
}

int interpolation_search(int arr[], int n, int x) {
    MEASURE_FUNC()

    int l = 0;
    int r = n - 1;

    while (l <= r && x >= arr[l] && x <= arr[r]) {
        if (l == r) {
            if (arr[l] == x)
                return l;
            return -1;
        }

        int p = l + ((x - arr[l]) * ((double)(r - l) / (arr[r] - arr[l])));

        if (arr[p] == x)
            return p;

        if (arr[p] > x)
            r = p - 1;
        else
            l = p + 1;
    }

    return -1;
}

int exp_search(int arr[], int n, int x) {
    MEASURE_FUNC()

    if (arr[0] == x)
        return 0;

    int i = 1;
    while (i < n && arr[i] < x)
        i *= 2;

    return binary_search(arr, i/2, min(i, n-1), x);
}