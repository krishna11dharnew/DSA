class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char,int>mp;
        int ans=0;
        int mxfr=0;
        int st=0;

        for(int e=0;e<s.size();e++)
        {
            mp[s[e]]++;
            mxfr=max(mxfr,mp[s[e]]);//mxfr = window ke andar kisi bhi character ki maximum frequency.
            while((e-st+1)-mxfr>k)//Agar required replacements k se jyada ho gaye,to window ko shrink karo.
            //Ek line mein yaad rakho:(window size - maximum frequency) > k= same character banane ke liye required changes > allowed changes → left se window shrink karo
            {
                mp[s[st]]--;
                st++;
            }
            ans=max(ans,e-st+1);
        }
        return ans;
    }
};
//window length - mxfr===Kitne characters ko change/replace karna padega taaki poori window same character ki ban jaye.