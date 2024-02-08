class Solution {
public:
    int maxel(vector<vector<int>>& a, int col) {
        int mx = INT_MIN;
        int idx=-1;
        for (int i = 0; i < a.size(); i++) {
            if(mx<a[i][col]){
                mx=a[i][col];
                idx=i;
            }
        }
        return idx;
    }

    vector<int> BS(vector<vector<int>>& a, int l, int h) {
        if (l > h) {
            return {-1, -1}; 
        }
        
        int mid = l + (h - l) / 2;
        int rmax = maxel(a, mid);
        int left = mid - 1 >= 0 ? a[rmax][mid - 1] : INT_MIN;
        int right = mid + 1 < a[0].size() ? a[rmax][mid + 1] : INT_MIN;
        int X = a[rmax][mid];
        
        if (X > left && X > right) {
            return {rmax, mid};
        } else if (left > X) {
            return BS(a, l, mid - 1);
        } else {
            return BS(a, mid + 1, h);
        }
    }

    vector<int> findPeakGrid(vector<vector<int>>& a) {
        int l = 0, h = a[0].size() - 1;
        return BS(a, l, h);
    }
};
