#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    string username;
    cin >> username;

    unordered_set<char> distinctChars;

    // Count distinct characters
    for(char c : username) {
        distinctChars.insert(c);
    }

    // Check if the count of distinct characters is odd
    if(distinctChars.size() % 2 == 1) {
        cout << "IGNORE HIM!" << endl;
    } else {
        cout << "CHAT WITH HER!" << endl;
    }

    return 0;
}