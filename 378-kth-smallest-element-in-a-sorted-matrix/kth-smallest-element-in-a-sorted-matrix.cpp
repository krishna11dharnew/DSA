class Solution {
    public :
    int ok(vector<vector<int>>&matrix,int mid,int n,int m)
    {
        int row=n-1;
        int col=0;
        int cnt=0;
        while(row>=0&&col<m)
        {
             if(matrix[row][col]<=mid)
             {
                cnt+=row+1;
                col++;
             }
             else
             {
                row--;
             }
        }
        return cnt;

        
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l=matrix[0][0];
        int n=matrix.size();
        int m=matrix[0].size();
        int r=matrix[n-1][m-1];
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(ok(matrix,mid,n,m)>=k)r=mid;
            else l=mid;
        }
        if(ok(matrix,l,n,m)>=k)return l;
        return r;
        
    }
};