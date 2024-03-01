class Solution {
public:
     string maximumOddBinaryNumber(string s) {
        int n=s.size(), o=count(s.begin(), s.end(), '1'), z=n-o;
        string ans=string(o-1, '1')+string(z, '0')+string(1,'1');
        return ans;
    }
};