class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>par(n);
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<i;j++)
          {
            if(nums[i]%nums[j]==0&&1+dp[j]>dp[i])
            {
                dp[i]=1+dp[j];
                par[i]=j;

            }
          }

        }
        int maxi=*max_element(dp.begin(),dp.end());
        int last=-1;
        for (int i = n - 1; i >= 0; i--) {
            if (dp[i] == maxi) {
                last= i;
                break;
            }
        }
        ans.push_back(nums[last]);
        while(par[last]!=last)
        {
          last=par[last];
          ans.push_back(nums[last]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};