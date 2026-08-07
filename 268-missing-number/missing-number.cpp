class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int i=0;
       int n=nums.size();
       while(i<n)
       {
        int correct=nums[i];
        if(nums[i]<n&&nums[i]!=nums[correct])
        {
            swap(nums[correct],nums[i]);

        }
        else
    {
        i++;
    }
       }
       for(int i=0;i<n;i++)
       {
        if(nums[i]!=i)return  i;
       }
       return n;
    }
};

// // class Solution {
// // public:
// //     int missingNumber(vector<int>& nums) {
// //         int n = nums.size();
// //         int total = n * (n + 1) / 2;
// //         int sum = 0;

// //         for (int num : nums) {
// //             sum += num;
// //         }

// //         return total - sum;
// //     }
// // };


// // class Solution {
// // public:
// //     int missingNumber(vector<int>& nums) {
// //         unordered_map<int, bool> mp;
// //         int n = nums.size();

// //         // Mark all present numbers
// //         for (int num : nums) {
// //             mp[num] = true;
// //         }

// //         // Find the missing number from 0 to n
// //         for (int i = 0; i <= n; ++i) {
// //             if (mp.find(i) == mp.end()) {
// //                 return i;
// //             }
// //         }

// //         return -1; // Should never reach here
// //     }
// // };



// // class Solution {
// // public:
// //     int missingNumber(vector<int>& nums) {
// //         sort(nums.begin(), nums.end());  // Sort required for binary search
// //         int l = -1;
// //         int r = nums.size();

// //         while (r - l > 1) {
// //             int m = (l + r) / 2;
// //             if (nums[m] == m) {
// //                 l = m;  // No missing till m, go right
// //             } else {
// //                 r = m;  // Missing number at or before m
// //             }
// //         }

// //         return r;
// //     }
// // };



// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());  // Required for BS
//         int n = nums.size();
//         int l = -1, r = n;

//         while (r - l > 1) {
//             int m = (l + r) / 2;

//             if (nums[m] > m) {
//                 r = m;  // mismatch, number missing on the left
//             } else {
//                 l = m;  // correct match, search right
//             }
//         }

//         return r;
//     }
// };

