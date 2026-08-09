class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
     {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }
        
            queue<pair<int,pair<int ,int>>>q;//{stops,{node,dis}}
            q.push({0,{src,0}});
            vector<int>dist(n,1e9);
            dist[src]=0;
            while(!q.empty())
            {
                auto it=q.front();
                q.pop();
                int stops=it.first;
                int node=it.second.first;
                int  cost=it.second.second;
                // if(stops>k) continue;
                for(auto iter:adj[node])
                {
                    int adjnode=iter.first;
                    int edwt=iter.second;
                    if(cost+edwt<dist[adjnode]&&stops<=k)
                    {
                        dist[adjnode]=cost+edwt;
                        q.push({stops+1,{adjnode,cost+edwt}});

                    }
                }
            }
            return (dist[dst] == 1e9) ? -1 : dist[dst];
        }
        
};