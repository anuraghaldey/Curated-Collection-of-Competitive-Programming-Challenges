class Solution {
public:
    
    
    bool isP(string& str) {
        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str[left] != str[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }

    string firstPalindrome(vector<string>& a) {
        for(int i=0;i<a.size();i++){
            if(isP(a[i])){
                return a[i];
            }
        }
        return "";
    }
};