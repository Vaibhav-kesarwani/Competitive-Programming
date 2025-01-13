#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n == 1 || n == 3)
        {
            cout << "-1\n";
        }
        else if (n % 2 == 0)
        {
            for (int i = 0; i < n - 2; i++)
            {
                cout << "3";
            }
            cout << "66\n";
        }
        else
        {
            for (int i = 0; i < n - 5; i++)
            {
                cout << "3";
            }
            cout << "36366\n";
        }
    }
}