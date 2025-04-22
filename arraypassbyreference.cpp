#include <bits/stdc++.h>
using namespace std;

void changeArray (int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] *=  2;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";
}

int main (void) {
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    changeArray(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
} 