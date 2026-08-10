class Solution {
    void dfs(int row,int col,vector<vector<char>>&grid,int n,int m)
    {
        grid[row][col]='0';
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nc>=0&&nc<m&&nr>=0&&nr<n&&grid[nr][nc]=='1')
            {
                dfs(nr,nc,grid,n,m);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    cnt++;
                    dfs(i,j,grid,n,m);
                }
            }
        }
    return cnt;
        
    }
};



// class Solution {
//     public:
//     void bfs(int row,int col, int n, int m, vector<vector<int>>&vis,vector<vector<char>>& grid )
//     {
//         vis[row][col]=1;
//         queue<pair<int,int>>q;
//         q.push({row,col});
//          int delrow[] = {-1, 0, 1, 0};
//           int delcol[] = {0, 1, 0, -1};

//         while(!q.empty())
//         {
//             int row=q.front().first;
//             int col=q.front().second;
//             q.pop();
//             for(int i=0;i<4;i++){
//                     int nrow=row+delrow[i];
//                     int ncol=col+delcol[i];
//                     if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]&&grid[nrow][ncol]=='1')
//                     {
//                         vis[nrow][ncol]=1;
//                         q.push({nrow,ncol});
//                     }
//                 }
//             }
//         }
    
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         int cnt=0;
//         vector<vector<int>>vis(n,vector<int>(m,0));
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(grid[i][j]=='1'&&!vis[i][j])
//                 {
//                     cnt++;
//                     bfs(i,j,n,m,vis,grid);
//                 }

//             }
//         }
//         return cnt;
        
//     }
// };


// class Solution {
// public:

//     void dfs(int row,int col,vector<vector<char>>& grid)
//     {
//         int n=grid.size();
//         int m=grid[0].size();

//         grid[row][col]='0';

//         int drow[]={-1,0,1,0};
//         int dcol[]={0,1,0,-1};

//         for(int i=0;i<4;i++)
//         {
//             int nrow=row+drow[i];
//             int ncol=col+dcol[i];

//             if(nrow>=0 && nrow<n &&
//                ncol>=0 && ncol<m &&
//                grid[nrow][ncol]=='1')
//             {
//                 dfs(nrow,ncol,grid);
//             }
//         }
//     }

//     int numIslands(vector<vector<char>>& grid)
//     {
//         int n=grid.size();
//         int m=grid[0].size();

//         int cnt=0;

//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(grid[i][j]=='1')
//                 {
//                     cnt++;
//                     dfs(i,j,grid);
//                 }
//             }
//         }

//         return cnt;
//     }
// };