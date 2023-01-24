#include <iostream>
int leftBinarySearch(int *arr, int key, int len) {
    int l = -1;
    int r = len;
    int mid;
    while (l < r - 1) {
        mid = l + (r - l) / 2;
        if (arr[mid] < key) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (r == len) {
        return 0;
    } else if (arr[r] == key) {
        return r + 1;
    } else {
        return 0;
    }
}

int rightBinarySearch(int *arr, int key, int len) {
    int l = -1;
    int r = len;
    int mid;
    while (l < r - 1) {
        mid = l + (r - l) / 2;
        if (arr[mid] <= key) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (l == -1) {
        return 0;
    } else if (arr[l] == key) {
        return l + 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    int m;
    std::cin >> n;
    std::cin >> m;
    int *arr_a = new int[n];
    int *arr_b = new int[m];
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        arr_a[i] = num;
    }
    for (int i = 0; i < m; ++i) {
        int num;
        std::cin >> num;
        arr_b[i] = num;
        int lbr = leftBinarySearch(arr_a, arr_b[i], n);
        std::cout << lbr;
        if (lbr == 0) {
            std::cout << std::endl;
        } else {
            std::cout << ' ';
            std::cout << rightBinarySearch(arr_a, arr_b[i], n) << std::endl;
        }
    }
    delete[] arr_a;
    delete[] arr_b;
}
