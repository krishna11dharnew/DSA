class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int maxending=nums[0];
        int minending=nums[0];
        int pro=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int v1=maxending*nums[i];
            int v2=minending*nums[i];
            int v3=nums[i];
            // maxending=max(v2,max(v1,v3));
            // minending=min(v3,min(v1,v2));
             maxending = max({v1, v2, v3});
            minending = min({v1, v2, v3});
            pro=max(pro,max(maxending,minending));
     }
     return pro;
    }
};