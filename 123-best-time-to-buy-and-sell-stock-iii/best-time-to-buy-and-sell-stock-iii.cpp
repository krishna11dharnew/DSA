class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int k=3;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(3,vector<int>(2,0)));
        for(int i=0;i<k;i++)
        {
            dp[0][i][0]=0;
            dp[0][i][1]=-prices[0];
        }
        for(int i=1;i<n;i++)
        {
            for(int k=1;k<=2;k++)
            {
                dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
                dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
            }
        }
        return dp[n-1][2][0];
        
    }
};