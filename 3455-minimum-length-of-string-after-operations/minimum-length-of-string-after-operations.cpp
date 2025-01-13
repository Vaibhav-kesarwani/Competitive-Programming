class Solution {
public:
    int minimumLength(string s) {
        ios::sync_with_stdio(0); cin.tie(0);
        vector<int>ct(26);
        for(char c:s) ct[c-'a']++;
        int res = 0;
        for(int i=0;i<26;i++) res += (ct[i]%2? 1 : (ct[i]? 2 : 0));
        return res;
    }
};