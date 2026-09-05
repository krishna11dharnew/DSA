class Solution {
public:
    bool solve(vector<int>&have,vector<int>&need)
    {
        for(int i=0;i<need.size();i++)
        {
            if(need[i]>have[i])
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int>need(256,0);
        vector<int>have(256,0);
        for(int i=0;i<t.size();i++)
        {
            need[t[i]]++;
        }
        int l=0;
        int st=0;
        int ans=1e9;
        for(int i=0;i<s.size();i++)
        {
            have[s[i]]++;
            while(solve(have,need))
            {
                if(i-st+1<ans)
                {
                    ans=i-st+1;
                    l=st;
                }
                have[s[st]]--;
                st++;
            }
        }
        if(ans==1e9) return "";
        return s.substr(l,ans);   
    }
};