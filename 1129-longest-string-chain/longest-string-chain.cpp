class Solution {
    bool solve(string s1,string s2)
    {
        if(s1.size()-1!=s2.size())return false;
        int i=0;
        int n=s1.size();//max length wale ki
        int j=0;
        while(i<n)
        {
            if(j<s2.size()&&s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(s1.size()==i&&j==s2.size()) return true;
        return false;


    }
   static  bool cmp(string &s1,string &s2)
    {
        return s1.size()<s2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n=words.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++)
        {
           for( int j=0;j<i;j++)
            {
                if(solve(words[i],words[j])&&1+dp[j]>dp[i])
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        int maxi=*max_element(dp.begin(),dp.end());
        return maxi;
        
    }
};