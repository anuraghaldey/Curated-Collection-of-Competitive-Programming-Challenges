class Solution {
public:
    int numberOfSubstrings(string a) {
        unordered_map<char,int>mp;
        int n=a.size();
        int i=0,j=0,end=n-1,ans=0;
        while(j<n){
            mp[a[j]]++;
            while(mp['a']&&mp['b']&&mp['c']){
                ans+=end-j+1;
                mp[a[i++]]--;
            }
            j++;
        }
        return ans;
    }
};