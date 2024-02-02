class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || nums[0] > nums[1]) {
            return 0;
        }
        if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }

        int l = 0, h = n - 1;  
        int ans = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;

            if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == n - 1 || nums[mid] > nums[mid + 1])) {
                ans = mid;
                break;
            }

            if (mid > 0 && nums[mid - 1] > nums[mid]) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
