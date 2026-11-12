class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int tempi = 1, tempd = 1;
        int maxi = 1, maxd = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                tempd++;
            } else {
                if (maxd < tempd) {
                    maxd = tempd;  
                }tempd = 1;
            }
            if (nums[i] < nums[i + 1]) {
                tempi++;
            } else {
                if (maxi < tempi) {
                    maxi = tempi;
                    
                }tempi = 1;
            }
        }
        if (maxd < tempd) {
            maxd = tempd;
            tempd = 1;
        }
        if (maxi < tempi) {
            maxi = tempi;
            tempi = 1;
        }
        return (maxi > maxd) ? maxi : maxd;
    }
};