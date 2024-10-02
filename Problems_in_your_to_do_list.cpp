#include <iostream>

using namespace std;

int main()
{

    // your code goes here

    int t;

    cin >> t;

    while (t--)
    {

        int n;

        cin >> n;

        int d[n], cnt = 0;

        for (int i = 0; i < n; i++)
        {

            cin >> d[i];

            if (d[i] >= 1000)
            {

                cnt++;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
