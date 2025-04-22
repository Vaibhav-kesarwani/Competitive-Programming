#include <iostream>
using namespace std;

int main (void) {
    int mark[5] = {10, 20, 30, 40, 50};
    int sizeofMarks = sizeof(mark) / sizeof(mark[0]);

    // Output of the array values
    for (int i = 0; i < sizeofMarks; i++) {
        cout << "mark[" << i << "] = " << mark[i] << endl;
    }

    int person[10];
    int sizeofPerson = sizeof(person) / sizeof(person[0]);

    // Input of the array values
    for (int i = 0; i < sizeofPerson; i++) {
        cin >> person[i];
    }

    return 0;
}