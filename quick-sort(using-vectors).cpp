#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quick_sort(vector<int>& arr, int begin, int end) {
    if (begin>=end) {
        return;
    } 
    else {
        int pi = partition(arr, begin, end);
        quick_sort(arr, begin, pi - 1);
        quick_sort(arr, pi + 1, end);
    }
}

int main() {
    vector<int> arr = {3, 2, 1, 4, 5, 6, 8, 7};
    quick_sort(arr, 0, arr.size() - 1);
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}
