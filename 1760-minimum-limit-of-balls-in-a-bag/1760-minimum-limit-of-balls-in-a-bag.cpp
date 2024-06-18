class Solution {
public:
    int check(vector<int>& a, int mid, int k) {
        int count = 0;
        int n=a.size();
        for (int i=0;i<n;i++) {
            count += (a[i] - 1) / mid;
        }
        return count<=k;
    }

    int bs(vector<int>& a, int l, int h, int &ans, int k) {
        if (l > h) {
            return ans;
        }
        int mid = l + (h - l) / 2;

        if (check(a, mid, k)) {
            ans = mid; 
            return bs(a, l, mid - 1, ans, k); 
        }
        return bs(a, mid + 1, h, ans, k); 
    }

    int minimumSize(vector<int>& a, int k) {
        int l = 1, h = *max_element(a.begin(), a.end());
        int ans = h;
        return bs(a, l, h, ans, k);
    }
};