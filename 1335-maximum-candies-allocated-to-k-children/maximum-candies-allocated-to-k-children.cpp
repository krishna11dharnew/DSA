class Solution {
    bool ok(int mid,vector<int>&candies,long long k)
    {
        long long  ans=0;
        for(int i=0;i<candies.size();i++)
        {
            
            ans+=(long long )candies[i]/mid;
        }
        return ans>=k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
         long long sum = 0;
        for (int x : candies)
            sum += x;

        if (sum < k)
            return 0;

        int l=0;
        int r=*max_element(candies.begin(),candies.end())+1;
        while(r-l>1)
        {
            int mid=(r+l)/2;
            if(ok(mid,candies,k)) l=mid;
            else r=mid;
        }
        return l;
    }
};