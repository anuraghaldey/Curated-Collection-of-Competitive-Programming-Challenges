class Solution {
public:
    int count(int val, vector<vector<int>>& matrix) {
        int res = 0;
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            int j = higherKey(matrix[i], val);
            res += j;
        }
        return res;
    }
    
    int higherKey(vector<int>& row, int val) {
        int n = row.size();
        if(row[n-1] <= val) return n;
        int l = 0, h = n-1;
        while(l < h) {
            int mid = l + (h - l) / 2;
            if(row[mid] <= val) l = mid + 1;
            else h = mid;
        }
        return h;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            int c = count(mid, matrix);
            if(c < k) low = mid + 1;
            else high = mid;
        }
        
        return high;
    }
};