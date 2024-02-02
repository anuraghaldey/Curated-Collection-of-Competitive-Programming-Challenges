class Solution {
public:
    int BS(vector<int>& a, int l, int h) {
        if (l == h) {
            return a[l];
        }

        int mid = l + (h - l) / 2;

        if (mid % 2 == 0) {
            if (a[mid] == a[mid + 1]) {
                return BS(a, mid + 1, h);
            } else {
                return BS(a, l, mid);
            }
        } else {
            if (a[mid] == a[mid - 1]) {
                return BS(a, mid + 1, h);
            } else {
                return BS(a, l, mid - 1);
            }
        }
    }

    int singleNonDuplicate(vector<int>& a) {
        return BS(a, 0, a.size() - 1);
    }
};
