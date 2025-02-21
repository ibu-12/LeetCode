class Solution {
public:
    void solve(vector<int>& nums, int target, int& c, int sum, int ind) {
        if (ind == nums.size()) {
            if (sum == target) c++;
            return;
        }

        // Include the current element with a positive sign
        solve(nums, target, c, sum + nums[ind], ind + 1);
        
        // Include the current element with a negative sign
        solve(nums, target, c, sum - nums[ind], ind + 1);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int c = 0;
        solve(nums, target, c, 0, 0);
        return c;
    }
};
