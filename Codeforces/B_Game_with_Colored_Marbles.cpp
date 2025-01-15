#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++)
    {
        int n;
        scanf("%d", &n);
        vector<int> c(n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &c[i]);
            --c[i];
        }
        vector<int> cnt(n);
        for(auto x : c) cnt[x]++;
        int exactly1 = 0, morethan1 = 0;
        for(auto x : cnt)
            if (x == 1)
                exactly1++;
            else if(x > 1)
                morethan1++;
        printf("%d\n", morethan1 + (exactly1 + 1) / 2 * 2);
    }
}