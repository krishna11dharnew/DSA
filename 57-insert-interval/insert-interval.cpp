class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        for(auto it:intervals)
        {
            ans.push_back(it);
        }
        ans.push_back(newInterval);
        sort(ans.begin(),ans.end());
        vector<vector<int>>ans1;
        for(auto it:ans)
        {
            if(ans1.empty()||ans1.back()[1]<it[0])
            {
                ans1.push_back(it);
            }
            else
            {
                ans1.back()[1]=max(ans1.back()[1],it[1]);
            }
        }
        return ans1;
        
    }
};