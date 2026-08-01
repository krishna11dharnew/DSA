class Solution {
public:
    bool isAnagram(string s, string t)
     {
        // if(s.size()!=t.size()) return false;
        // unordered_map<char,int>mp1;
        // unordered_map<char,int>mp2;
        // for(int i=0;i<s.size();i++)
        // {
        //     char ch=s[i];
        //     mp1[ch]++;
        //     char chh=t[i];
        //     mp2[chh]++;

        // }
        // return mp1==mp2;




        int freq[26]={0};
         for(char c:s)
         {
            freq[c-'a']++;
         }
         for(char c:t)
         {
            freq[c-'a']--;
         }
         for(int i=0;i<26;i++)
         {
            if(freq[i]!=0) return false;
         }
         return true;
    }
    
};