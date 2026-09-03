class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        dp[0]=nums[0];
        int ans=dp[0];
        for(int i=1;i<n;i++)
        {
             dp[i]=max(dp[i-1]+nums[i],nums[i]);
             ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};



// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int bestending=nums[0];
//         int sum=nums[0];
//         for(int i=1;i<nums.size();i++)
//         {
//             int v1=nums[i]+bestending;
//             int v2=nums[i];
//             bestending=max(v1,v2);
//             sum=max(sum,bestending);
//         }
//         return sum;
        
//     }
// };


// // bestEnding = current index tak ka maximum subarray sum
// // sum = ab tak ka overall maximum subarray sum