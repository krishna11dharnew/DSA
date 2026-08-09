class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> d(n, vector<int>(n, 1e9));

        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];

            d[u][v]=w;
            d[v][u]=w;
        }

        for(int i=0;i<n;i++)
            d[i][i]=0;

        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    // if(d[i][k]==1e9 || d[k][j]==1e9)
                    //     continue;

                    d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
                }
            }
        }

        int cntcity=n;
        int cityno=-1;

        for(int city=0;city<n;city++)
        {
            int cnt=0;

            for(int adjcity=0;adjcity<n;adjcity++)
            {
                if(d[city][adjcity]<=distanceThreshold)
                    cnt++;
            }

            if(cnt<=cntcity)
            {
                cntcity=cnt;
                cityno=city;
            }
        }

        return cityno;
    }
};