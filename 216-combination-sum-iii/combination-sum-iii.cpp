class Solution {
public:
    void solve(int idx,int target,vector<int>&ds,vector<vector<int>>&ans,vector<int>& candidates,int k)
    {
        if(target==0&&ds.size()==k)
        {
            ans.push_back(ds);
            return ;
        }
        for(int i=idx;i<candidates.size();i++)
         {
        //     if(i>idx&&candidates[i]==candidates[i-1])
        //     {
        //         continue;
        //     }
        //     if(candidates[i]>target)
        //     {
        //         break;
        //     }
            ds.push_back(candidates[i]);
            solve(i+1,target-candidates[i],ds,ans,candidates,k);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int>candidates={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,n,ds,ans,candidates,k);
        return ans;
        
    }
};