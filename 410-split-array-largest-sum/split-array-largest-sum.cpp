class Solution {
public:
bool ok(int mid,vector<int>&nums,int k)
{
    int cnt=1;
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        if(sum>mid)
        {
            cnt++;
            sum=nums[i];
        }
    }
    return cnt<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end())-1;
        int sum=-1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];

        }
        int r=sum+1;
        while(r-l>1)
        {
            int m=(l+r)/2;
            if(ok(m,nums,k)) r=m;
            else 
            {
                l=m;
            }
        }
        return r;
    }
};