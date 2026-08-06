class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return false;
        
        int right_boundary = n - 1;
        
        // 1. Trimming duplicates from the end
        while(right_boundary > 0 && nums[right_boundary] == nums[0]) {
            right_boundary--;
        }

        // 2. Find Pivot (sabse chota element)
        int pivot = 0; 
        // BUG FIX: <= lagaya taaki right_boundary wala element bhi check ho
        for(int i = 1; i <= right_boundary; i++) {
            if(nums[i] < nums[i-1]) {
                pivot = i;
                break;
            }
        }

        // 3. First BS (0 se pivot-1 tak)
        int l = -1;
        int r = pivot;
        while(r - l > 1) {
            int mid = (l + r) / 2;
            if(nums[mid] == target) return true;
            if(nums[mid] >= target) r = mid;
            else l = mid;
        }

        // 4. Second BS (pivot se end tak)
        l = pivot - 1;
        r = right_boundary+1; // Yahan r = n theek hai, kyunki aage ke duplicates answer kharab nahi karenge
        while(r - l > 1) {
            int mid = (l + r) / 2;
            if(nums[mid] == target) return true;
            if(nums[mid] >= target) r = mid;
            else l = mid;
        }
        
        return false;
    }
};

// class Solution {
// public:
//     bool search(vector<int>& nums, int target)  {
//         int l=-1;
//         int n=nums.size();
//         int r=nums.size();
//         while(r-l>1)
//         {
//             int mid=(l+r)/2;
//             if(nums[mid]==target)return true;
            
//             int low=l+1;
//             int high=r-1;
//             if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
//                 // Hume nahi pata kaunsa half sorted hai.
//                 // Par hume pata hai ki nums[mid] target nahi hai, toh low/high bhi nahi honge.
//                 // Isliye dono boundaries ko 1-1 step shrink kar do.
//                 l++; 
//                 r--;
//                 continue; // Wapas naya mid calculate karne jao
//             }
//             if(nums[low]<=nums[mid])
//             {
//                 if(nums[low]<=target&&target<nums[mid])r=mid;
//                 else l=mid;

//             }
//             else
//             {
//              if(nums[mid]<target&&target<=nums[high])l=mid;
//              else r=mid;
//             }

//         }
//         return false;

        
//     }
// };

// class Solution {
// public:
//     bool search(vector<int>& nums, int target)
//     {
//         int n = nums.size();
//         int l = -1;
//         int r = n;

//         while(r - l > 1)
//         {
//             int m = (l + r) / 2;

//             if(nums[m] == target) return true;

//             // ⭐ handle duplicates safely
//             if(m > 0 && m < n-1 && nums[m] == nums[m-1] && nums[m] == nums[m+1])
//             {
//                 l = m;   // shrink left
//                 continue;
//             }

//             // left part sorted
//             if(nums[0] <= nums[m])
//             {
//                 if(nums[0] <= target && target < nums[m])
//                     r = m;
//                 else
//                     l = m;
//             }
//             // right part sorted
//             else
//             {
//                 if(nums[m] < target && target <= nums[n-1])
//                     l = m;
//                 else
//                     r = m;
//             }
//         }

//         return false;
//     }
// };