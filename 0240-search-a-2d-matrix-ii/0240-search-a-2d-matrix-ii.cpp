class Solution {
public:
    bool BS(vector<vector<int>>& a, int r, int c, int k, int n) {
        if (r >= n || c < 0) {
            return false;
        }
        if (a[r][c] == k) {
            return true;
        } else if (a[r][c] < k) {
            return BS(a, r + 1, c, k, n);
        }
        return BS(a, r, c - 1, k, n);
    }

    bool searchMatrix(vector<vector<int>>& m, int target) {
        if (m.empty() || m[0].empty()) {
            return false;
        }
        int rows = m.size();
        int cols = m[0].size();
        return BS(m, 0, cols - 1, target, rows);
    }
};
