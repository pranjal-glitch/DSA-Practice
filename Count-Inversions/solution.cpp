#include <bits/stdc++.h>
using namespace std;

long long merge(long long *arr, int low, int mid, int high) {
    vector<long long> temp;

    int i = low;
    int j = mid + 1;

    long long count = 0;

    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            count += (mid - i + 1);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int k = low; k <= high; k++) {
        arr[k] = temp[k - low];
    }

    return count;
}

long long mergeSort(long long *arr, int low, int high) {
    if(low >= high) {
        return 0;
    }

    int mid = low + (high - low) / 2;

    long long count = 0;

    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);

    return count;
}

long long getInversions(long long *arr, int n) {
    return mergeSort(arr, 0, n - 1);
}
