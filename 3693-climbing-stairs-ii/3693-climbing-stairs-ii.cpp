class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        const int INF = INT_MAX / 2;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= 3 && j - k >= 0; k++) {
                dp[j] = min(dp[j], dp[j - k] + costs[j - 1] + k * k);
            }
        }
        return dp[n];
    }
};