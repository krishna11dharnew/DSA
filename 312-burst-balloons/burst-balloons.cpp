class Solution {
    int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp)//solve(i, j) = maximum coins by bursting balloons from i to j
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long ans=LLONG_MIN;
        for(int k=i;k<=j;k++) // Try every balloon as the LAST balloon to burst
        {
            int left=solve(i,k-1,nums,dp);
            int right=solve(k+1,j,nums,dp);

            // Since k is burst LAST,
            // its neighbours are fixed:
            // left boundary = nums[i-1]
            // right boundary = nums[j+1]
            int cost=nums[i-1]*nums[k]*nums[j+1];
            long long total=left+right+cost;
            ans=max(ans,total);
        }
        return dp[i][j]=ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(1,n-2,nums,dp);

        
    }
};