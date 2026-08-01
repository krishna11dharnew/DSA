class Solution {
public:
    int beautySum(string s) {
        
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int>frq(26,0);
            for(int j=i;j<n;j++)
            {
                frq[s[j]-'a']++;
                int maxi=0;
                int mini=INT_MAX;
                for(int k=0;k<26;k++)
                {
                    if(frq[k]==0)continue;
                    maxi=max(maxi,frq[k]);
                    mini=min(mini,frq[k]);
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
        
    }
};