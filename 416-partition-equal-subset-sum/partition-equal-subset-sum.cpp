class Solution {
public:
    bool f(vector<int>& arr, int n, int sum,
                        vector<vector<int>>& dp) {

        if (sum == 0)
            return 1;

        if (n <= 0)
            return 0;

        if (dp[n][sum] != -1)
            return dp[n][sum];

        if (arr[n - 1] > sum)
            return dp[n][sum] = f(arr, n - 1, sum, dp);
        else {

            return dp[n][sum] =
                       f(arr, n - 1, sum, dp) ||
                       f(arr, n - 1, sum - arr[n - 1], dp);
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if(sum%2!=0)return false;
        sum = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return f(nums, n,sum, dp);
    }
};