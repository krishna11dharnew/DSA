
class DisjointSet {
public:
    vector<int> parent, rank, size;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n,0);
        size.resize(n,1);

        for(int i=0;i<n;i++)
            parent[i]=i;
    }

    int findUPar(int node) {
        if(node==parent[node])
            return node;

        return parent[node]=findUPar(parent[node]);
    }

    bool find(int u,int v) {
        return findUPar(u)==findUPar(v);
    }

    void unionBySize(int u,int v) {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u==ulp_v)
            return;

        if(size[ulp_u]<size[ulp_v]) {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
    int n=stones.size();
    DisjointSet ds(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            // if(i==j) continue;
            if(stones[i][0]==stones[j][0]|| stones[i][1]==stones[j][1] )
            {
                ds.unionBySize(i,j);
            }
        }
    }
     int cnt = 0;

        for(int i=0;i<n;i++)
        {
            if(ds.findUPar(i)==i)
                cnt++;
        }

        return n-cnt;

        


    }
};