class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it:mp)
        {
            int number=it.first;
            int frq=it.second;
            pair<int,int>curr={frq,number};
            if(pq.size()<k)
            {
                pq.push(curr);
                continue;
            }
            if(pq.top().first>curr.first)continue;
            pq.pop();
            pq.push(curr);
        }
        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};