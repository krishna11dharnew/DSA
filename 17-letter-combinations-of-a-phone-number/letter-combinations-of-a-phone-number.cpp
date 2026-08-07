class Solution {
    void solve(string digits,string mapping[],string ds,int idx,vector<string>&ans)
    {
        if(idx>=digits.size())
        {
            ans.push_back(ds);
            return ;
        }
        int digit=digits[idx]-'0';
        string k=mapping[digit];
        for(int i=0;i<k.size();i++)
        {
            ds.push_back(k[i]);
            solve(digits,mapping,ds,idx+1,ans);
            ds.pop_back();
        }

    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0) return ans;
        string ds="";
        int idx=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,mapping,ds,idx,ans);
        return ans;
        
    }
};


// class Solution {
//     public:
//     void solve(string digits,vector<string>&ans,int index,string mapping[],string &output)
//     {
//         if(index>=digits.length())
//         {
//             ans.push_back(output);
//             return;
//         }
//         int number=digits[index]-'0';
//         string value=mapping[number];
//         for(int i=0;i<value.length();i++)
//         {
//             output.push_back(value[i]);
//             solve(digits,ans,index+1,mapping,output);
//             output.pop_back();
//         }
//     }
// public:
//     vector<string> letterCombinations(string digits) {
//         vector<string>ans;
//         if(digits.length()==0)
//         {
//             return ans;
//         }
//         string output="";
//         int index=0;
//         string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//         solve(digits,ans,index,mapping,output);
//         return ans;
        
//     }
// };