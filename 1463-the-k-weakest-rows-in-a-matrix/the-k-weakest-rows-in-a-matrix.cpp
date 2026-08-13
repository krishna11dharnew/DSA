class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<mat.size();i++)
        {
            int sol=0;
            while(sol<mat[i].size() && mat[i][sol]==1)
            {
                sol++;
            }
            if(pq.size()<k)
            {
                pq.push({sol,i});
                continue;
            }
            if(pq.top().first<=sol)continue;
            pq.pop();
            pq.push({sol,i});
        }
        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};