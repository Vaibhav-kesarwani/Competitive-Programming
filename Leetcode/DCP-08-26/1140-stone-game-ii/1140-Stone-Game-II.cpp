class Solution {
public:
    int findScore(vector<vector<vector<int>>>&dp,vector<int>&arr,int i,int M,int n,int person)
    {
        if(i>=n) return 0;
        if(dp[i][M][person]!=-1) return dp[i][M][person];
        int stones=0;
        int score;
        if(person==1) score=-1;
        else score=INT_MAX;
        for(int x=1;x<=min(n-i,2*M);x++)
        {
            stones+=arr[i+x-1];
            if(person==1)
            {
                score=max(score,stones+findScore(dp,arr,i+x,max(x,M),n,0));
            }
            else
            {
                score=min(score,findScore(dp,arr,i+x,max(x,M),n,1));
            }
        }
        return dp[i][M][person]=score;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return findScore(dp,piles,0,1,n,1);
    }
};