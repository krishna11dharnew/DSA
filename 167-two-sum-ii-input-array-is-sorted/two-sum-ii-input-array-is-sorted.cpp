// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//          int s=0;
//          int n=numbers.size();
//         int j=numbers.size()-1;
//         for(int i=0;i<numbers.size();i++)
//         {
//             int s=0;
//             int l=n-1;
//             while(l>s)
//             {
//                 if(numbers[s]+numbers[l]==target)
//                 {
//                     return {s+1,l+1};
//                 }
//                 else if(numbers[s]+numbers[l]<target)
//                 {
//                     s++;

//                 }
//                 else
//                 {
//                     l--;
//                 }
//             }
//         }
//         return {-1,-1};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    
        unordered_map<int,int>mp;
        
        for(int i=0;i<numbers.size();i++)
        {
             int ques=target-numbers[i];
            
             if(mp.find(ques)!=mp.end())
             {
                return {mp[ques]+1,i+1};
             }
             mp[numbers[i]]=i;

        }
        return {-1,-1};
    }
};