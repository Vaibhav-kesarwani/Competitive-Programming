#include <bits/stdc++.h>
using namespace std;

int main (void) {
    int a[] = {4, 2, 7, 1, 2, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int start{}, end{n - 1};

    for (int i = 0; i < n; i++) {
        if (start >= end) {
            break;
        }
        swap(a[start], a[end]);
        start++;
        end--;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}