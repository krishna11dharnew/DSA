class Solution {
    int solve(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    {
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long long  ans=LLONG_MAX;
        for(int k=i;k<=j;k++)
        {
            int left=solve(i,k-1,cuts,dp);
            int right=solve(k+1,j,cuts,dp);
            int cost=(cuts[j+1]-cuts[i-1]);
            long long total=left+right+cost;
            ans=min(ans,total);

        }
        return dp[i][j]=ans;


    }
public:
    int minCost(int n, vector<int>& cuts) {
        //dp[i][j] =cut i se cut j ke beech tk minimum cost

        sort(cuts.begin(),cuts.end());

        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int m=cuts.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return solve(1,m-2,cuts,dp);


    }
};