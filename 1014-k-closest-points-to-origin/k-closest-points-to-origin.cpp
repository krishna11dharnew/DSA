class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>pq;//{distance,point}
        for(auto it:points)
        {
            int x=it[0];
            int y=it[1];
            int d=x*x+y*y;
            if(pq.size()<k)
            {
                pq.push({d,it});
                continue;
            }
            if(pq.top().first<d) continue;
            pq.pop();
            pq.push({d,it});
        }
        vector<vector<int>>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};