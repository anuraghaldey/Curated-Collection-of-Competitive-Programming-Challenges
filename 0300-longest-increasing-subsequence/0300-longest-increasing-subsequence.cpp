#include <vector>
using namespace std;

class Solution {
public:
    bool check(int mid, vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        int maxLength = 0;
        for (int len : dp) {
            maxLength = max(maxLength, len);
        }
        
        return mid <= maxLength;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int l = 1, h = nums.size(), ans = 1;
        
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(mid, nums)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        
        return ans;
    }
};
