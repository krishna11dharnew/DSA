class Solution {
    struct cmp
    {
        bool operator()(pair<int,int>&a,pair<int,int>&b)
        {
            if(a.first!=b.first)
            {
                return a.first<b.first;
            }
            return a.second<b.second;
        }
    };
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        for(int i=0;i<arr.size();i++)
        {
             int d=abs(arr[i]-x);
             if(pq.size()<k)
             {
                pq.push({d,arr[i]}); continue;
             }
             if(pq.top().first<=d) continue;
             pq.pop();
             pq.push({d,arr[i]});
        }
        vector<int>ans;
        while(!pq.empty())
        {
           ans.push_back(pq.top().second);
           pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};