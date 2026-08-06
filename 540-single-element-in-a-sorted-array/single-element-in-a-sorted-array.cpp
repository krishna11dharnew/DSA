class Solution {
    public:
    bool ok(int mid,vector<int>&nums)
    {
        if(mid%2==1)mid--;
        if (mid + 1 >= nums.size()) return true;
        return nums[mid]!=nums[mid+1];
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=-1;
        int r=nums.size();
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(ok(mid,nums))r=mid;
            else
            {
                l=mid;
            }
        }
        return nums[r];

        
    }
};
// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int ans=0;
//         for(int i=0;i<nums.size();i++)
        
//         {
//             ans=ans^nums[i];
//         }
//         return ans;
//     }
// };