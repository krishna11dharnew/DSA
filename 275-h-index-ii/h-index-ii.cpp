class Solution {
    bool ok(vector<int>&cit,int mid)
    {
        int cnt=0;
        for(int i=0;i<cit.size();i++)
        {
            if(cit[i]>=mid) cnt++;
        }
        return cnt>=mid;
    }
public:
    int hIndex(vector<int>& citations) {
        // if(citations.size()==1) return citations[0];
        int l=-1;
         int r = citations.size() +1;
        while(r-l>1)
        {
            int mid=l+(r-l)/2;
            if(ok(citations,mid))l=mid;
            else r=mid;
        }
        return l;
        
    }
};