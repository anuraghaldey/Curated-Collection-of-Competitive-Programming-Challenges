class Solution {
public:
    int bs(const std::vector<int>& a, int l, int h, int x) {
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (a[mid] == x) return mid;
            else if (a[mid] < x) l = mid + 1;
            else h = mid - 1;
        }
        return l;
    }

    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        int n = arr.size();
        int idx = bs(arr, 0, n - 1, x);
        vector<int> result;
        int left = idx - 1, right = idx;
        
        while (k--) {
            if (left < 0) {
                result.push_back(arr[right]);
                right++;
            } else if (right >= n) {
                result.push_back(arr[left]);
                left--;
            } else {
                if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                    result.push_back(arr[left]);
                    left--;
                } else {
                    result.push_back(arr[right]);
                    right++;
                }
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};