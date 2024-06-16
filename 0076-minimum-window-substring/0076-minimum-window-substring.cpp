class Solution {
public:
    bool is_valid(map<char, int> &window, map<char, int> &tar){
        for (auto &v : tar) {
            if (window[v.first] < v.second) {
                return false;
            }
        }
        return true;
    }
    bool check(string &s, map<char, int> &mp, int k, int &st, int &en) {
        int n = s.size();
        map<char, int> mp1;
        for (int i = 0; i < k; i++) {
            mp1[s[i]]++;
        }
        if (is_valid(mp1, mp)) {
            st = 0;
            en = k - 1;
            return true;
        }
        for (int i = k; i < n; i++) {
            mp1[s[i - k]]--;
            if (mp1[s[i - k]] == 0) {
                mp1.erase(s[i - k]);
            }
            mp1[s[i]]++;
            if (is_valid(mp1, mp)) {
                st = i - k + 1;
                en = i;
                return true;
            }
        }
        return false;
    }

    

    int bs(string &s, int l, int h, map<char, int> &mp, int &ans, int &st, int &en) {
        if (l > h) {
            return ans;
        }
        int mid = l + (h - l) / 2;
        if (check(s, mp, mid, st, en)) {
            ans = mid;
            return bs(s, l, mid - 1, mp, ans, st, en);
        }
        return bs(s, mid + 1, h, mp, ans, st, en);
    }

    string minWindow(string s,string t) {
        int m = s.size(), n = t.size();
        int l = 1, h = m, ans = -1;
        int st = -1, en = -1;
        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[t[i]]++;
        }
        ans = bs(s, l, h, mp, ans, st, en);
        if (ans == -1) return "";
        return s.substr(st, en - st + 1);
    }
};
