class Solution {
    void dfs(vector<vector<int>>& image,int sr,int sc,int color,int inicolor,int n,int m)
    {
        int row=sr;
        int col=sc;
        image[row][col]=color;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
          int nr=row+dr[i];
          int nc=col+dc[i];
          if(nr>=0&&nr<n&&nc>=0&&nc<m&&image[nr][nc]==inicolor)
          {
            dfs(image,nr,nc,color,inicolor,n,m);
          }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int inicolor=image[sr][sc];
         if(color == inicolor)
            return image;
        int n=image.size();
        int m=image[0].size();
        dfs(image,sr,sc,color,inicolor,n,m);       
        return image; 
    }
};