#include <iostream>
using namespace std;

int main (void) {
    int arr[5] = {10, 20, 30, 40, 50};
    int maxi = INT_MIN;
    int mini = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        if (a[i] > maxi) maxi = a[i];
        if (mini > a[i]) mini = a[i];
    }

    cout << maxi << "\n"; // Output of the maximum value
    cout << mini << "\n"; // Output of the minimum value

    return 0;
}