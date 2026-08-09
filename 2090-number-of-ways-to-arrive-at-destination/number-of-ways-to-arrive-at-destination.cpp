class Solution {
public:
    int  mod=1e9+7;

    int countPaths(int n, vector<vector<int>>& roads) 
    {

        vector<pair<int,int>> adj[n];

        for(int i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        vector<long long> dis(n,1e18);
        vector<int> ways(n,0);

        dis[0]=0;
        ways[0]=1;

        pq.push({0,0});

        while(!pq.empty())
        {
            auto itn=pq.top();
            pq.pop();

            long long dist=itn.first;
            int node=itn.second;

            if(dist>dis[node])
                continue;

            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int edwt=it.second;

                if(dist+edwt<dis[adjnode])
                {
                    dis[adjnode]=dist+edwt;
                    ways[adjnode]=ways[node];
                    pq.push({dis[adjnode],adjnode});
                }
                else if(dist+edwt==dis[adjnode])
                {
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }

        return ways[n-1];
    }
};