class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n);

        int pos = 0;   // Even indices
        int neg = 1;   // Odd indices

        // Traverse the array
        for (int i = 0; i < n; i++) {

            // Place positive numbers
            if (nums[i] > 0) {
                ans[pos] = nums[i];
                pos += 2;
            }
            // Place negative numbers
            else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;
    }
};