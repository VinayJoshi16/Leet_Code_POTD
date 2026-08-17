class Solution {
public:
    vector<vector<int>> dp;

    bool solve(vector<int>& nums, int n, int sum) {

        if (sum == 0)
            return true;

        if (n == 0)
            return false;

        if (dp[n][sum] != -1)
            return dp[n][sum];

        if (nums[n - 1] <= sum) {

            bool take = solve(nums, n - 1, sum - nums[n - 1]);

            bool nottake = solve(nums, n - 1, sum);

            return dp[n][sum] = take || nottake;
        }

        return dp[n][sum] = solve(nums, n - 1, sum);
    }

    bool canPartition(vector<int>& nums) {

        int total = 0;

        for (int x : nums) {
            total += x;
        }

        if (total % 2 != 0)
            return false;

        int target = total / 2;

        int n = nums.size();

        dp.assign(n + 1, vector<int>(target + 1, -1));

        return solve(nums, n, target);
    }
};