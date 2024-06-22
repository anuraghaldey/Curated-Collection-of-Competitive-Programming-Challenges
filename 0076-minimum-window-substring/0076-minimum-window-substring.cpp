class Solution {
public:
    int check(map<char, int>&windowfreq, char ch, map<char, int>&tfreq) {
        for (auto v : tfreq) {
            if (v.first == ch) {
                if (windowfreq[v.first] + 1 < v.second) {
                    return false;
                }
            } else {
                if (windowfreq[v.first] < v.second) {
                    return false;
                }
            }
        }
	    return true;
    }
    string minWindow(string s,string t) {
        

        int n = s.size(), m = t.size();

        map<char, int>tfreq;
        for (int i = 0; i < m; i++) {
            tfreq[t[i]]++;
        }
        int ans = n + 1;
        int tail = 0, head = -1;
        map<char, int>windowfreq;
        int best_idx=-1;

        while (tail < n) {
            while (head + 1 < n && !check(windowfreq, s[head + 1], tfreq)) {
                head++;
                windowfreq[s[head]]++;
            }
            if (head + 1 < n ) {
                int len = head - tail + 2;
                if (len < ans) {
                    ans = len;
                    best_idx = tail;
                }
		    }
            if (tail > head) {
                tail++;
                head = tail - 1;
            }
            else {
                windowfreq[s[tail]]--;
                tail++;
            }
        }

        return ans==n+1?"":s.substr(best_idx,ans);
    }
};
