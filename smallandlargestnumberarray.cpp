#include <bits/stdc++.h>
using namespace std;

int main (void) {
    int a[5] = {10, 20, 30, 40, 50};
    int n = sizeof(a) / sizeof(a[0]);
    int maxi = INT_MIN;
    int mini = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (a[i] > maxi) maxi = a[i];
        if (mini > a[i]) mini = a[i];
    }

    auto largeIndex = find(a, a + n, maxi);
    auto smallIndex = find(a, a + n, mini);

    cout << maxi << "\n"; // Output of the maximum value
    cout << mini << "\n"; // Output of the minimum value

    cout << largeIndex - a << "\n"; // Output of the index of the maximum value
    cout << smallIndex - a << "\n"; // Output of the index of the minimum value

    return 0;
}